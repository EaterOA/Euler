#include <iostream>

#define N 100

int powOf(int a)
{
	for (int i = 2; i*i <= a; i++) {
		if (a % i == 0) {
			int pow = 0, temp = a;
			for (; temp % i == 0; temp /= i, pow++);
			if (temp == 1)
				return pow;
		}
	}
	return 1;
}

int main()
{
	int overlap[6+1] = {0};
	bool used[6*N+1] = {0};
	for (int pow = 1; pow < 6+1; pow++) {
		for (int b = 2*pow; b <= N*pow; b += pow) {
			if (used[b]) overlap[pow]++;
			used[b] = 1;
		}
	}
	int sum = 0;
	for (int a = 2; a <= N; a++)
		sum += N - 1 - overlap[powOf(a)];
	std::cout << sum << "\n";
}