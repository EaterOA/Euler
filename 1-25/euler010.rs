fn main() {
    let primes = get_primes(2000000);
    let mut sum: i64 = 0;
    for pr in primes {
        sum += pr as i64
    }
    println!("{}", sum);
}

fn get_primes(p: i32) -> Vec<i32> {
    let mut primes = Vec::new();
    let sievebound: usize = ((p-1)/2) as usize;
    let crossbound: usize = ((p as f64).sqrt() as usize - 1) / 2;
    let mut sieve = vec![false; sievebound+1];
    for i in 1..crossbound+1 {
        if !sieve[i] {
            let mut j = 2*i*(i+1);
            while j <= sievebound {
                sieve[j] = true;
                j += 2*i+1;
            }
        }
    }
    if p >= 2 {
        primes.push(2);
    }
    for i in 1..sievebound+1 {
        if !sieve[i] {
            primes.push((2*i+1) as i32);
        }
    }
    primes
}
