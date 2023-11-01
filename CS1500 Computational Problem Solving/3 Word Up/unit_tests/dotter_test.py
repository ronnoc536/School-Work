#!/usr/bin/python3
# -*- coding: utf-8 -*-

import os
import sys

# Temporarily add the current path to the system path for importing the student's source code.
sys.path.append(
    os.path.join(
        os.path.dirname(os.path.dirname(os.path.abspath(__file__))), ".admin_files"
    )
)
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
# python3 seemingly respects only abspaths, while ipython3 is ok with relative, like '..' here.
import test_utils


@test_utils.test_wrapper
def test() -> bool:
    import word_up
    from typing import List, Tuple

    # To debug in pudb3, highlight just below this line, hit 't', then 'n' or 's' as you want
    matrix: List[List[str]] = [
        ["m", "n", "j", "j", "f", "i", "x"],
        ["f", "t", "y", "g", "a", "w", "x"],
        ["q", "d", "o", "t", "t", "e", "r"],
        ["e", "j", "w", "w", "x", "m", "k"],
        ["m", "b", "m", "x", "s", "j", "m"],
        ["i", "q", "d", "k", "p", "s", "t"],
        ["v", "r", "w", "u", "c", "b", "s"],
    ]
    student_result: Tuple[Tuple[int, int]] = word_up.matrix_search(matrix, "dotter")
    return student_result == ((2, 1), (2, 6))


if __name__ == "__main__":
    test()
