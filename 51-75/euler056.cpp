#include <iostream>

int main()
{
	int maxSum = 0;
	for (int a = 99; a >= 90; a--) {
		short d[200] = {0};
		d[0] = 1;
		int l = 1;
		for (int b = 0; b < 99; b++) {
			for (int dig = 0; dig < l; dig++) d[dig] *= a;
			for (int dig = 0; dig <= l; dig++) {
				if (d[dig] && dig == l) l++;
				d[dig+1] += d[dig] / 10;
				d[dig] %= 10;
			}
			if (b > 89) {
				int sum = 0;
				for (int n = 0; n < l; n++) sum += d[n];
				if (sum > maxSum) maxSum = sum;
			}
		}
	}
	std::cout << maxSum << "\n";
}