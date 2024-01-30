pub fn caesar_translate(input_text: String, mode: String, key: isize) -> String {
    // Purpose:    Does the Caesar cipher logic.
    // Parameters: input_text to translate,
    //             mode (encrypt or decrypt), and
    //             key (in size).
    // User Input: None.
    // Prints:     None.
    // Returns:    Translated text as a std::String.
    // Modifies:   Nothing.
    // Calls:      Pure rust, no imports. Hint: rem_euclid
    // Tests:      ./unit_tests/*
    // Status:     Do this one!
    // asserteq!(caesar_translate("abc".to_string(), "encrypt".to_string(), 1), "bcd".to_string())
    // asserteq!(caesar_translate("bcd".to_string(), "decrypt".to_string(), 1), "abc".to_string())

    let symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 !?.";
    let mut translated = String::new();
    let mut symbol_index: isize;
    let mut translated_index: isize;

    for symbol in input_text.chars() {
        if symbols.contains(symbol) {
            symbol_index = symbols.find(symbol).unwrap() as isize;
            if mode == "encrypt" {
                translated_index = (symbol_index + key).rem_euclid(66);
            } else {
                translated_index = (symbol_index - key).rem_euclid(66);
            }
            translated
                .push_str(&symbols[translated_index as usize..(translated_index + 1) as usize]);
        } else {
            translated.push_str(&symbol.to_string());
        }
    }
    return translated;
}
