#!/usr/bin/python3
# -*- coding: utf-8 -*-

import skbio  # type: ignore
import sys
import scipy as sp  # type: ignore
import functools
import collections
from typing import Tuple


def kmer_distance(
    sequence1: skbio.Sequence,
    sequence2: skbio.Sequence,
    k: int = 3,
    overlap: bool = True,
) -> float:
    """Compute the kmer distance between a pair of sequences

    Parameters
    ----------
    sequence1 : skbio.Sequence
    sequence2 : skbio.Sequence
    k : int, optional
        The word length.
    overlapping : bool, optional
        Defines whether the k-words should be overlapping or not
        overlapping.

    Returns
    -------
    float
        Fraction of the set of k-mers from both sequence1 and
        sequence2 that are unique to either sequence1 or
        sequence2.

    Raises
    ------
    ValueError
        If k < 1.

    Notes
    -----
    k-mer counts are not incorporated in this distance metric.

    """
    sequence1_kmers = set(map(str, sequence1.iter_kmers(k=k, overlap=overlap)))
    sequence2_kmers = set(map(str, sequence2.iter_kmers(k=k, overlap=overlap)))
    all_kmers = sequence1_kmers | sequence2_kmers
    shared_kmers = sequence1_kmers & sequence2_kmers
    number_unique = len(all_kmers) - len(shared_kmers)
    fraction_unique = number_unique / len(all_kmers)
    return fraction_unique


def progressive_msa(
    sequences: "skbio.SequenceCollection",
    pairwise_aligner: skbio.alignment.global_pairwise_align_nucleotide,
    guide_tree: skbio.TreeNode = None,
) -> skbio.TabularMSA:
    """Perform progressive msa of sequences

    Parameters
    ----------
    sequences : skbio.SequenceCollection
        The sequences to be aligned.
    metric : function, optional
      Function that returns a single distance value when given a pair of
      skbio.Sequence objects. This will be used to build a guide tree if one
      is not provided.
    guide_tree : skbio.TreeNode, optional
        The tree that should be used to guide the alignment process.
    pairwise_aligner : function
        Function that should be used to perform the pairwise alignments,
        for example skbio.alignment.global_pairwise_align_nucleotide. Must
        support skbio.Sequence objects or skbio.TabularMSA objects
        as input.

    Returns
    -------
    skbio.TabularMSA

    """

    if guide_tree is None:
        guide_dm = skbio.DistanceMatrix.from_iterable(
            iterable=sequences, metric=kmer_distance, key="id"
        )
        guide_lm = sp.cluster.hierarchy.average(y=guide_dm.condensed_form())
        guide_tree = skbio.TreeNode.from_linkage_matrix(
            linkage_matrix=guide_lm, id_list=guide_dm.ids
        )

    seq_lookup = {s.metadata["id"]: s for i, s in enumerate(sequences)}

    # working our way down, first children may be super-nodes,
    # then eventually, they'll be leaves
    c1, c2 = guide_tree.children

    # Recursive base case
    if c1.is_tip():
        c1_aln = seq_lookup[c1.name]
    else:
        c1_aln = progressive_msa(
            sequences=sequences, pairwise_aligner=pairwise_aligner, guide_tree=c1
        )

    if c2.is_tip():
        c2_aln = seq_lookup[c2.name]
    else:
        c2_aln = progressive_msa(
            sequences=sequences, pairwise_aligner=pairwise_aligner, guide_tree=c2
        )

    # working our way up, doing alignments, from the bottom up
    alignment, _, _ = pairwise_aligner(seq1=c1_aln, seq2=c2_aln)

    # this is a temporary hack as the aligners in skbio 0.4.1 are dropping
    # metadata - this makes sure that the right metadata is associated with
    # the sequence after alignment
    if isinstance(c1_aln, skbio.Sequence):
        alignment[0].metadata = c1_aln.metadata
        len_c1_aln = 1
    else:
        for i in range(len(c1_aln)):
            alignment[i].metadata = c1_aln[i].metadata
        len_c1_aln = len(c1_aln)
    if isinstance(c2_aln, skbio.Sequence):
        alignment[1].metadata = c2_aln.metadata
    else:
        for i in range(len(c2_aln)):
            alignment[len_c1_aln + i].metadata = c2_aln[i].metadata

    # feed alignment back up, for further aligment, or eventually final return
    return alignment


def progressive_msa_and_tree(
    sequences: "skbio.SequenceCollection",
    pairwise_aligner: skbio.alignment.global_pairwise_align_nucleotide,
    guide_tree: skbio.TreeNode = None,
    display_aln: bool = False,
    display_tree: bool = False,
) -> Tuple[skbio.TabularMSA, skbio.TreeNode]:
    """Perform progressive msa of sequences and build a UPGMA tree
    Parameters
    ----------
    sequences : skbio.SequenceCollection
        The sequences to be aligned.
    pairwise_aligner : function
        Function that should be used to perform the pairwise alignments,
        for example skbio.alignment.global_pairwise_align_nucleotide. Must
        support skbio.Sequence objects or skbio.TabularMSA objects
        as input.
    metric : function, optional
      Function that returns a single distance value when given a pair of
      skbio.Sequence objects. This will be used to build a guide tree if one
      is not provided.
    guide_tree : skbio.TreeNode, optional
        The tree that should be used to guide the alignment process.
    display_aln : bool, optional
        Print the alignment before returning.
    display_tree : bool, optional
        Print the tree before returning.

    Returns
    -------
    skbio.alignment
    skbio.TreeNode

    """
    msa = progressive_msa(
        sequences=sequences, pairwise_aligner=pairwise_aligner, guide_tree=guide_tree
    )

    if display_aln:
        print(msa)

    msa_dm = skbio.DistanceMatrix.from_iterable(
        iterable=msa, metric=kmer_distance, key="id"
    )
    msa_lm = sp.cluster.hierarchy.average(y=msa_dm.condensed_form())
    msa_tree = skbio.TreeNode.from_linkage_matrix(
        linkage_matrix=msa_lm, id_list=msa_dm.ids
    )
    if display_tree:
        print("\nOutput tree:")
        d = sp.cluster.hierarchy.dendrogram(
            msa_lm,
            labels=msa_dm.ids,
            orientation="right",
            link_color_func=lambda x: "black",
        )
    return msa, msa_tree


input_file = sys.argv[1]
output_file = sys.argv[2]

query_sequences = []
sequences = collections.OrderedDict()
for seq in skbio.io.read(input_file, format="fasta"):
    seq_id = seq.metadata["description"]
    sequences[seq_id] = skbio.DNA(sequence=seq, metadata={"id": seq_id})
    query_sequences.append(skbio.DNA(sequence=seq, metadata={"id": seq_id}))


global_pairwise_align_nucleotide = functools.partial(
    skbio.alignment.global_pairwise_align_nucleotide, penalize_terminal_gaps=True
)

msa, tree = progressive_msa_and_tree(
    sequences=query_sequences,
    pairwise_aligner=global_pairwise_align_nucleotide,
    display_tree=False,
    display_aln=False,
)

msa_dm = skbio.DistanceMatrix.from_iterable(
    iterable=msa, metric=skbio.sequence.distance.hamming, key="id"
)


sequence_you_index = msa_dm.ids.index("Sequence_You")
sequence_you_data = msa_dm[sequence_you_index]
zipped_data = list(zip(sequence_you_data, msa_dm.ids))
ordered = sorted(zipped_data)


def convert_family_str(index: int) -> str:
    if index == 0:
        return "Sequence_You"
    elif index <= 2:
        return "Sequence_Parent"
    elif index > 2 and index <= 6:
        return "Sequence_Grandparent"
    else:
        return "ERROR OUT OF RANGE"


ordered_lineage = {}
for index, i in enumerate(ordered):
    key = i[1]
    value = convert_family_str(index)
    ordered_lineage[key] = value


with open(output_file, "w") as f:
    for sequence in skbio.io.read(input_file, format="fasta"):
        sequence.metadata["description"] = ordered_lineage[
            sequence.metadata["description"]
        ]
        sequence.write(f)
