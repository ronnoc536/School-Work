fn main() {
    // Purpose:    Parses args, reads/writes files, calls apply_key
    // Parameters: None
    // User Input: None
    // Prints:     Nothing
    // Returns:    Nothing
    // Modifies:   Nothing
    // Calls:      std::
    // Tests:      arg_tests/
    // Status:     Do this one.

    let args: Vec<String> = std::env::args().collect();
    let keyfile = &args[1];
    let key_being_used: usize = args[2].parse().expect("Error: main() Encryt.rs");
    let input_file = &args[3];
    let output_file = &args[4];
    let in_string = std::fs::read_to_string(input_file).expect("Error: Reading in input file");
    let key = std::fs::read(keyfile).expect("Error: Reading in key file");

    let bytes_from_key = &key[key_being_used * 256..(key_being_used + 1) * 256];
    let out_string = apply_key(&bytes_from_key.to_vec(), &in_string);

    std::fs::write(output_file, out_string).expect("Error: Writing to output file");
}

pub fn apply_key(key: &Vec<u8>, in_str: &String) -> String {
    // Purpose:    Applies OTP to the in_str based on the key
    // Parameters: A vector of bytes and a unicode string of equal length by chars
    // User Input: None
    // Prints:     Nothing
    // Returns:    A std::String of the same character length as the input string
    // Modifies:   Nothing
    // Calls:      std::
    // Tests:      unit_tests/
    // Status:     Do this one.
    let mut out_str = String::new();
    for (index, character) in in_str.chars().enumerate() {
        let key_byte = key[index];
        let in_byte = character as u8;
        let out_byte = key_byte ^ in_byte;
        out_str.push(out_byte as char);
    }
    out_str
}
