#include <iostream>

int main()
{
	int fifth[10];
	for (int n = 0; n < 10; n++) fifth[n] = n*n*n*n*n;
	int total = 0;
	for (int n = 10; n < 354295; n++) {
		int num = n, sum = 0;
		for (; num > 0; num /= 10)
			sum += fifth[num % 10];
		if (n == sum)
			total += n;
	}
	std::cout << total << "\n";
}
