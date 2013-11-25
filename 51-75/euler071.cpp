#include <iostream>

int main()
{
	double closest = 0, base = 3./7;
	int n, d;
	for (int den = 1000000; den > 8; den--) {
		if (den % 7 == 0) continue;
		int num = base * den;
		double f = (double)num / den;
		if (f > closest) {
			closest = f;
			n = num;
			d = den;
		}
	}
	std::cout << n << "\n";
}