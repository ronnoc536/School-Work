use std::fs::File;
use std::io::{self, Read, Write};
mod eve;

fn main() {
    let args: Vec<String> = std::env::args().collect();

    let (alice_broadcasts, bob_broadcasts, public_base, public_modulus) = if args.len() < 3 {
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Error");
        let alice_broadcasts = input.trim().parse().expect("Error");

        input.clear();
        io::stdin().read_line(&mut input).expect("Error");
        let bob_broadcasts = input.trim().parse().expect("Error");

        input.clear();
        io::stdin().read_line(&mut input).expect("Error");
        let public_base = input.trim().parse().expect("Error");

        input.clear();
        io::stdin().read_line(&mut input).expect("Error");
        let public_modulus = input.trim().parse().expect("Error");

        (
            alice_broadcasts,
            bob_broadcasts,
            public_base,
            public_modulus,
        )
    } else {
        let mut input_file = File::open(&args[1]).expect("Error");
        let mut input_str = String::new();
        input_file.read_to_string(&mut input_str).expect("Error");

        let inputs: Vec<&str> = input_str.split_whitespace().collect();

        let alice_broadcasts = inputs[0].parse().expect("Error");
        let bob_broadcasts = inputs[1].parse().expect("Error");
        let public_base = inputs[2].parse().expect("Error");
        let public_modulus = inputs[3].parse().expect("Error");

        (
            alice_broadcasts,
            bob_broadcasts,
            public_base,
            public_modulus,
        )
    };

    let outputs = eve::big_eve(
        alice_broadcasts,
        bob_broadcasts,
        public_base,
        public_modulus,
    );

    let output_str: String = outputs
        .iter()
        .map(|i| i.to_string())
        .collect::<Vec<String>>()
        .join(" ");

    if args.len() < 3 {
        println!("{}", output_str);
    } else {
        let mut output_file = File::create(&args[2]).expect("Error");
        output_file.write_all(output_str.as_bytes()).expect("Error");
    }
}
