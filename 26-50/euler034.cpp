#include <iostream>

int main()
{
	int factorial[10] = {1};
	for (int n = 1; n < 10; n++)
		factorial[n] = factorial[n-1] * n;
	int totSum = 0;
	for (int n = 10; n < 2540160; n++) {
		int tempN = n, sum = 0;
		for (; tempN > 0; sum += factorial[tempN%10], tempN /= 10);
		if (sum == n)
			totSum += n;
	}
	std::cout << totSum << "\n";
}