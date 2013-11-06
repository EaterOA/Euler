#include <iostream>

#define N 10
#define P 1000000

long long permute(int d, long long order, bool used[], int pass);
int fac(int n);

int main()
{
	bool used[N] = {0};
	std::cout << permute(0, 0, used, P) << "\n";
}

long long permute(int d, long long order, bool used[], int pass)
{
	for (int i = 0; i < N; i++) {
		if (!used[i]) {
			if (pass > fac(N-1-d))
				pass -= fac(N-1-d);
			else {
				used[i] = 1;
				return permute(d+1, order * 10 + i, used, pass);
			}
		}
	}
	return order;
}

int fac(int n)
{
	int product = 1;
	for (; n > 1; n--)
		product *= n;
	return product;
}