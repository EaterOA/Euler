#include <iostream>

#define N 100

int main()
{
	int num[2*N] = {0};
	num[0] = 1;
	for (int n = 2; n <= N; n++) {
		for (int m = 2*N-3; m >= 0; m--) {
			num[m] *= n;
			num[m+1] += num[m] / 10 % 10;
			num[m+2] += num[m+1] / 10 + num[m] / 100;
			num[m+1] %= 10;
			num[m] %= 10;
			for (int o = m + 2; num[o] >= 10; o++) {
				num[o+1] += num[o] / 10;
				num[o] %= 10;
			}
		}
	}
	int sum = 0;
	for (int n = 2*N-1; n >= 0; n--)
		sum += num[n];
	std::cout << sum << "\n";
}