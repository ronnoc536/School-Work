# Programming assignment 2 (pa02) -- Binary One Time Pad
Binary XOR operations are all over modern crypto.
This is a fun implementation of "perfect" crypto.
You will also learn more Rust basics.

Ferris the delicious decapod thinks this assignment gets 10 legs up...
Is that the same as 2 thumbs up, in decimal base 10??

![binary perfection?](perfect10.jpg)

## Background
https://cs-mst.gitlab.io/index/Classes/Security/Content/06-OneTimePad.html

https://git-classes.mst.edu/taylorpat/python-otp
This is the example past assignment in python.
It's a little different in the way the files are written,
but everything else is very similar.

## Files
The primary Rust files to modify are: `encrypt.rs` and `generate_keys.rs`.

1. A Rust file named `generate_keys.rs`.
This file is executed as follows: 

`cargo run --bin=gen_keys <key_file_to_write>`

```
cargo run --bin=gen_keys keyfile.sec
```
which should output a **binary** file of 50 keys, 
each 2048 bits long, 
with each bit randomly generated.
So, the file should be `50*2048` bits long.

These bits should be generated randomly,
in a cryptographically strong manner,
using the "rand" crate (https://docs.rs/rand/latest/rand/).

2. A Rust File named `encrypt.rs`. 
This file is executed as:

`cargo run -bin=program <key_file_to_read> <key_number> <input_utf8_file> <output_utf8_file>`

```
cargo run -bin=program keyfile.sec 3 inputfile.txt outputfile.txt
```
which should:
turn the text in `inputfile.txt` into a vector of bytes (vec of u8),
based on each character's unicode code point, one byte per character.
In this assignment, all character code points are guaranteed to be 255 or less,
so they can be safely compressed into a byte.
<https://en.wikipedia.org/wiki/Code_point#In_character_encoding>
XOR that byte vector with the bytes of the 4th key in `keyfile.sec`,
convert it back to a unicode string,
write the resulting data to `outputfile.txt`.

Thus, the script should work symmetrically, 
encrypting or decrypting.
The encrypted message may look like ASCII junk,
so don’t worry if it does! 
Check out `arg_tests/inputs/*`
to see what such junk is supposed to look like.
Input parameters could be named any valid filename, and numbers in range.

Note: 
The input file will be exactly 256 ASCII/UTF-8 characters long.

## What to submit
You could have testing files like messages and keys in the repository,
but just the two Rust files are necessary.

## General notes:
Read the syllabus procedures about file format and code running environment.
The Rust files are expected to run in an up-to-date classVM 
(your linux machine is probably fine,
but make sure the code runs on the Gitlab Docker CI/CD job).

## Due Date
On Canvas.

## Notes
A vec of u8 might seem like a strange way to handle byte objects.
When a grader and I wrote this, it seemed like the most canonical solution.
If you can find a more natural Rusty way, I'd be happy to hear it!

The message length will always be the exact length of the key in binary,
so you don't have to pad or un-pad the message.

In general, reading and writing files come in binary and string-based versions.
A "read to string" is different than a "read".

When you read the text file that's supposed to be encrypted/decrypted,
you will have to decode each "character" into its code point,
storing in a vec of u8, to then encrypt it.

Similarly, when you write the encrypted "text" file,
so that the encrypt/decrypt operations are entirely symmetrical,
while still being easily transmissable via text.
In Rust, you can write a vec of u8 directly to a file!

When you read and write the keys (vec of u8) to the keyfile,
it should be in binary mode.

The result of the above constraints,
is that executing your code on the same message over and over,
should just reverse it back and forth.
If you are not recovering your original message by executing repeatedly,
your implementation does not work!
As you saw with the previous two assignments,
we test with many keys, since some sneaky characters cause bugs.

I am (admittedly) being loose with calling byte-characters UTF-8/ASCII encoding.

Have fun and good luck!
