/* TODO This unit test needs:
 * exception handling
 * a decorator
 */
#[path = "../src/encrypt.rs"]
#[allow(dead_code)]
mod encrypt;
#[path = "../src/generate_keys.rs"]
#[allow(dead_code)]
mod generate_keys;
use rand::distributions::{Alphanumeric, DistString};

fn main() {
    let args: Vec<String> = std::env::args().collect();
    if args.len() < 2 {
        println!("Must include returncode as arg")
    }
    let desired_retcode = &args[1];
    let desired_retcode: i32 = desired_retcode
        .trim()
        .parse()
        .expect("Please type a number!");

    for _ in 0..50 {
        let mut rng = rand::thread_rng();
        let in_str: String = Alphanumeric.sample_string(&mut rng, 256);
        let key: Vec<u8> = generate_keys::generate_keys(1);
        let out_str = encrypt::apply_key(&key, &in_str);
        let orig_str = encrypt::apply_key(&key, &out_str);
        if in_str != orig_str {
            std::process::exit(1);
        }
    }
    std::process::exit(desired_retcode);   
}
