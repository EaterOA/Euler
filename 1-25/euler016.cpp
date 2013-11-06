#include <iostream>

#define N 1000

int main()
{
	int num[N] = {0};
	num[0] = 1;
	for (int n = 0; n < N; n++) {
		for (int m = N-2; m >= 0; m--) {
			num[m] *= 2;
			num[m+1] += num[m] / 10;
			num[m] %= 10;
		}
	}
	int sum = 0;
	for (int n = 0; n < N; n++)
		sum += num[n];
	std::cout << sum << "\n";
}