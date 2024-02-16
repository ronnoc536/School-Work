/* TODO This unit test needs:
 * exception handling
 * a decorator
 */
#[path = "../src/encrypt.rs"]
#[allow(dead_code)]
mod encrypt;

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
    
    let in_str: String = String::from("Howdy there!");
    let key: Vec<u8> = vec![3, 34, 55, 22, 79, 122, 23, 27, 4, 0, 175, 130];
    let goal_str = String::from("KM@r6ZcsarÊ£");
    let out_str = encrypt::apply_key(&key, &in_str);
    if out_str != goal_str {
        std::process::exit(1);  
    }
    else {
        std::process::exit(desired_retcode);
    }
}
