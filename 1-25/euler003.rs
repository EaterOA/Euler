fn main() {
    let mut n: i64 = 600851475143;
    let mut highest = 0;
    let mut i = 2;
    while n > 1 {
        while n % i == 0 {
            highest = i;
            n /= i;
        }
        i += 1;
    }
    println!("{}", highest);
}
