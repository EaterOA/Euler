#include <iostream>

int main()
{
	int num = 1, den = 1;
	for (int d = 11; d < 100; d++) {
		if (d%10 == 0) continue;
		for (int n = 10; n < d; n++) {
			if (n%10 == 0) continue;
			double value = double(n)/d;
			if (d%10 == n%10 && double(n/10)/(d/10) == value ||
				d/10 == n%10 && double(n/10)/(d%10) == value ||
				d%10 == n/10 && double(n%10)/(d/10) == value ||
				d/10 == n/10 && double(n%10)/(d%10) == value) {
				num *= n;
				den *= d;
			}
		}
	}
	for (int n = 2; n <= num; n++)
		for (; num % n == 0 && den % n == 0; num /= n, den /= n);
	std::cout << den << "\n";
}