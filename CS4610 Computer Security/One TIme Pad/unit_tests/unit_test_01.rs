/* TODO This unit test needs:
 * exception handling
 * a decorator
 */
#[path = "../src/generate_keys.rs"]
#[allow(dead_code)]
mod generate_keys;
use rand::Rng;

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
    
    let mut rng = rand::thread_rng();
    for _i in 0..10 {
        let num_keys = rng.gen_range(30..100);
        let key_length = 256;
        let keys = generate_keys::generate_keys(num_keys);

        if keys.len() != num_keys * key_length {
            std::process::exit(1);   
        }
    }
    std::process::exit(desired_retcode);
}
