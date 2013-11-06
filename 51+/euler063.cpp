#include <iostream>

int numDigits(double n)
{
	int digits = 0;
	for (; n >= 1; n /= 10) digits++;
	return digits;
}

int main()
{
	int sum = 0;
	for (int power = 1;; power++) {
		int subTot = 0;
		for (int base = 1; base < 10; base++) {
			double num = 1;
			for (int m = 0; m < power; m++) num *= base;
			if (numDigits(num) == power) subTot++;
		}
		if (subTot == 0) break;
		sum += subTot;
	}
	std::cout << sum << "\n";
}