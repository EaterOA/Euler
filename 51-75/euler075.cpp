#include <iostream>
#include <math.h>

using namespace std;

#define MAXL 1500001

int gcd(int a, int b)
{
	int c;
	while (b) {
		c = b;
		b = a % b;
		a = c;
	}
	return a;
}

int main()
{
	//Can cut memory by half since all valid l are even, but that's hyperoptimization territory
    char list[MAXL] = {0};
    int crossbound = (int)sqrt((double)MAXL);
    for (int m = 2; m <= crossbound; m++) {
        for (int n = 1; n < m; n += 2) {
			//(m-n) must be odd
			if ((m-n)%2 == 0) {
				n--;
				continue;
			}
			int l = 2*m*(m + n); //Reduced form of Euclid's formula
			if (l >= MAXL) break;
            if (list[l] <= 1 && gcd(m, n) == 1) {
				for (int i = l; i < MAXL; i += l)
					list[i]++;
            }
        }
    }
    int res = 0;
    for (int i = 1; i < MAXL; i++)
        if (list[i] == 1)
            res++;
    cout << res << endl;
}
