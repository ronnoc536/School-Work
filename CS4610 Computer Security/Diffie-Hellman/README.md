# pa02 Crack Diffie Helmen
Your job is to program Eve the crabby eavesdropper in Rust!
Alice and Bob and trying to keep secrets using their iPhones.
Eve works at Apple, on the iMessage team.
Eve is curious what Alice and Bob need that secret for.
Your goal is to write a simple Rust program to crack the secret, to satisfy Eve's curiosity.

![](crabby_apple.jpg)

Re-read:

https://cs-mst.gitlab.io/index/Classes/Security/Content/07-CryptoMath.html

https://cs-mst.gitlab.io/index/Classes/Security/Content/08-AsymmetricEncryption.html#diffie-hellman-1

https://en.wikipedia.org/wiki/Diffie%E2%80%93Hellman_key_exchange

https://en.wikipedia.org/wiki/Primitive_root_modulo_n


## Part 1: Crack the baby version of DH
Crack a weaker conceptual cousin to DH, using secret exponents without mod.
This weaker version is described here:

1. Alice and bob email each other to pick a shared base:
$`SharedBase`$

2. Alice emails the shared base to the power of her secret:
$`AliceBroadcasts = SharedBase^{AliceSec}`$

3. Bob emails the shared base to the power of his secret:
$`BobBroadcasts = SharedBase^{BobSec}`$

4. Alice generates the shared secret:
$`BobBroadcasts^{AliceSec}`$

5. Bob generates same shared secret:
$`AliceBroadcasts^{BobSec}`$

For `baby_eve` you only need to implement the function itself,
and the only tests of it are the `unit_tests/`.

## Part 2: Big Eve - Crack the real DH
Program a solution that mimics the baby version in structure,
but with the real logic (brute force from the bottom up).
To complete this section, you should write the `big_eve` function in `src/eve.rs`.
In addition to the `unit_tests/`,
the `stdio_tests/` and `arg_tests/` also test this function.
Main is only intended to run `big_eve`.

## Tests

### unit\_tests/
Trace this in `gdb` to check it out!
We randomize some small baby eve problem instances.

### stdio\_tests/
Your program will assume that three numbers are entered via the keyboard input, 
1 at a time, Alice's Broadcast, Bob's Broadcast, Public Base, and Public Modulus.
It should then print Alice's Secret, Bob's Secret, and the Mutual Secret on one line.

### arg\_tests/
You will be given two line arguments containing the input file and the output file.
From the input file, you will read Alice's Broadcast, Bob's Broadcast, Public Base, and Public Modulus.
In the output file, put Alice's Secret, Bob's Secret, and the Mutual Secret.

## Running your Code
All code should fit in the `src/` directory (we have your files already there).
Your main driver will be in `src/main.rs`.
['The Book'](https://doc.rust-lang.org/book/ch01-03-hello-cargo.html).
Below are references to the commands you will use the most.

- `cargo build` : Compiles your code and puts it in `target/debug/name_specified_in_cargo.toml`
- `cargo run` : Compiles and runs your code, allowing interaction with it for stdio testing.
    - May require a --bin if you have multiple binaries (as this assignment does with it's unit test).
- `cargo run arg1 arg2` : Compiles and runs your code, passing along any number of arguments you need, for arg-based testing.
- `cargo run --bin=randomized_test_big 123` for example, making sure your exit code is 123 (or the same as any number you specify).

## Hint
The number types in Rust only go up to 64-bit (128-bit if you are using u128).
This is not large enough to allow for large keys to be cracked.
All inputs will be small enough to be handled in the u64 variable types.
The usage of a BigInt is not required for the basic baby eve.
Read the unit tests before starting!
