#include <iostream>

int numfac(int n)
{
	int nf = 1;
	for (int pf = 2; pf <= n; pf++) {
		int comb = 1;
		for (; n % pf == 0; n /= pf, comb++);
		nf *= comb;
	}
	return nf;
}

int main()
{
	for (int n = 1, tri = 1;; n++, tri += n)
		if (numfac(tri) > 500) {
			std::cout << tri << "\n";
			break;
		}
}