#include <iostream>

int main()
{
	long long last10 = 0;
	for (int i = 1; i <= 1000; i++) {
		long long tempLast10 = 1;
		for (int j = 1; j <= i; j++)
			tempLast10 = (tempLast10 * i) % 10000000000LL;
		last10 = (tempLast10 + last10) % 10000000000LL;
	}
	std::cout << last10 << "\n";
}