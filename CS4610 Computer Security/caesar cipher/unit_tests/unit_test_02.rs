/* TODO This unit test needs:
 * exception handling
 * a decorator
 */
#[path = "../src/crabby_caesar.rs"]
mod crabby_caesar;

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
    if crabby_caesar::caesar_translate("bcd".to_string(), "decrypt".to_string(), 1) == "abc".to_string() {
        std::process::exit(desired_retcode);
    } else {
        std::process::exit(1);
    }
}
