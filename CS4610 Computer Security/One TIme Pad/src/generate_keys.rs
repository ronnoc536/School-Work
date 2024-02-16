use rand::Rng;
use std::fs;

pub fn generate_keys(num_keys: usize) -> Vec<u8> {
    // Purpose:    Gets a random vector of bytes, with each key being 2048 bits
    // Parameters: The number of keys
    // User Input: None
    // Prints:     Nothing
    // Returns:    A Vec<u8> containing the bytes of num_keys keys
    // Modifies:   Nothing
    // Calls:      std:: , rand::
    // Tests:      unit_tests/
    // Status:     Do this one.
    let mut keys: Vec<u8> = Vec::new();
    let mut rng = rand::thread_rng();

    for i in 0..num_keys {
        for i in 0..=255 {
            let need_to_push = rng.gen_range(0..=255);
            keys.push(need_to_push);
        }
    }
    keys // return vector of keys
}

fn main() {
    // Purpose:    Parses the args for this file, and writes the keyfile
    // Parameters: None
    // User Input: None
    // Prints:     Nothing
    // Returns:    Nothing
    // Modifies:   Nothing
    // Calls:      std::
    // Tests:      custom_test (see grade.sh)
    // Status:     Do this one.

    let args: Vec<String> = std::env::args().collect();
    let name_of_file = &args[1];
    let keys = generate_keys(50);
    fs::write(name_of_file, keys).expect("Unable to write file");
}
