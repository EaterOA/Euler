#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	for (int n = 999; n --> 100;) {
		int p = n * 1000 + (n % 10) * 100 + (n % 100 / 10) * 10 + n / 100;
		double limit = sqrt((double)p);
		for (int m = 999; m >= limit; m--) {
			if (p % m == 0) {
				cout << p << "\n";
				return 0;
			}
		}
	}
}