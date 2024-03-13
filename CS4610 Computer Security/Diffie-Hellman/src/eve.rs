pub fn baby_eve(alice_broadcasts: u64, bob_broadcasts: u64, public_base: u64) -> [u64; 3] {
    // Purpose:     Crack baby DH
    // Parameters:  alice's broadcast, bob's broadcast, and the public base
    // User-input:  None
    // Prints:      Nothing
    // Returns:     Should return an array of 3 unsigned ints:
    //              Alice's secret, Bob's secret, shared secret
    // Modifies:    Nothing
    // Calls:       ?
    // Tests:       unit_test_babydh.rs
    // Status:      Done, correct, but is it ideal?
    let alice_secret: u64 =
        ((alice_broadcasts as f64).log10() / (public_base as f64).log10()) as u64;
    let bob_secret: u64 = ((bob_broadcasts as f64).log10() / (public_base as f64).log10()) as u64;
    let shared_secret = (alice_broadcasts as u64).pow(bob_secret as u32);
    return [alice_secret, bob_secret, shared_secret];
}

pub fn big_eve(
    alice_broadcasts: u64,
    bob_broadcasts: u64,
    public_base: u64,
    public_modulus: u64,
) -> [u64; 3] {
    // Purpose:      Crack real DH (albeit not with huge numbers)
    // Parameters:   Alice's broadcast, Bob's broadcast, the public base and modulus of DH.
    // User-input:   None
    // Prints:       Nothing
    // Returns:      Should return an array of 3 ints:
    //               Alice's secret, Bob's secret, shared secret
    // Modifies:     Nothing
    // Calls:        ?
    // Test:         ./unit_tests/unit_test_babydh.rs
    // Status:       TODO delete the 0 placeholders, and replace with real computations
    let mut alice_secret: u64 = 1;
    let mut bob_secret: u64 = 1;

    while ((alice_broadcasts as u64)
        .pow(bob_secret as u32)
        .rem_euclid(public_modulus)
        != (bob_broadcasts as u64)
            .pow(alice_secret as u32)
            .rem_euclid(public_modulus)
        || (public_base as u64)
            .pow(alice_secret as u32)
            .rem_euclid(public_modulus)
            != alice_broadcasts
        || (public_base as u64)
            .pow(bob_secret as u32)
            .rem_euclid(public_modulus)
            != bob_broadcasts)
        && alice_secret < public_modulus
    {
        bob_secret += 1;

        if bob_secret >= public_modulus {
            alice_secret += 1;
            bob_secret = 1;
        }
    }

    let shared_secret = (alice_broadcasts as u64)
        .pow(bob_secret as u32)
        .rem_euclid(public_modulus);

    return [alice_secret, bob_secret, shared_secret];
}
