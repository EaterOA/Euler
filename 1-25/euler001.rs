fn sum(n: i32, accum: i32) -> i32 {
    if n <= 0 { accum }
    else if n % 3 == 0 { sum(n-1, accum+n) }
    else if n % 5 == 0 { sum(n-1, accum+n) }
    else { sum(n-1, accum) }
}

fn main() {
    println!("{}", sum(999, 0));
}
