#include <iostream>
#include <algorithm>

int nDigits(unsigned long long num)
{
	int count = 0;
	for (; num > 0; num /= 10) count++;
	return count;
}

int main()
{
	int ans = 0;
	unsigned long long n = 1, d = 2;
	for (int i = 0; i < 1000; i++) {
		if (nDigits(n+d) > nDigits(d)) ans++;
		n += d+d;
		std::swap(n,d);
		//Approximation by dropping last term to avoid need for clunky BigInteger
		if (n > (1ULL<<61)) {
			n /= 10;
			d /= 10;
		}
	}
	std::cout << ans << "\n";
}