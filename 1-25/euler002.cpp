#include <iostream>

int main()
{
	int sum = 0;
	for (int fibo1 = 1, fibo2 = 2; fibo2 <= 4000000;) {
		if (fibo2 % 2 == 0)
			sum += fibo2;
		fibo2 += fibo1;
		fibo1 = fibo2 - fibo1;
	}
	std::cout << sum << "\n";
}