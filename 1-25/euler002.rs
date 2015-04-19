fn main() {
    let mut x = 0;
    let mut y = 1;
    let mut sum = 0;
    while y <= 4000000 {
        if y % 2 == 0 {
            sum += y;
        }
        let z = x;
        x = y;
        y += z;
    }
    println!("{}", sum);
}
