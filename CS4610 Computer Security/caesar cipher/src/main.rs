mod crabby_caesar;
use std::io;

fn main() {
    // Purpose:    IO, and calls your functions.
    // Parameters: None
    // User Input: Input text to translate
    // Prints:     Print result
    // Returns:    Nothing
    // Modifies:   Nothing outside its scope
    // Calls:      std::
    // Tests:      stdio_tests/
    // Status:     Do this one.
    let mut message = String::new();
    let mut mode = String::new();
    let mut input_key = String::new();
    let real_key: isize;

    println!("Enter a string to translate:");
    io::stdin()
        .read_line(&mut message)
        .expect("Failed to read line");

    while (mode != "encrypt") && (mode != "decrypt") {
        mode = String::new();
        println!("encrypt or decrypt?");
        io::stdin()
            .read_line(&mut mode)
            .expect("Failed to read line");
        mode = mode.trim().to_string();
    }

    println!("What is your key?");
    io::stdin()
        .read_line(&mut input_key)
        .expect("Failed to read line");

    real_key = input_key.trim().parse().unwrap();

    println!(
        "{}",
        crabby_caesar::caesar_translate(message, mode, real_key)
    );
}
