#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define P 10000

bool sieve[(P-1)/2+1];

void getPrimes()
{
	int sievebound = (P-1)/2;
	int crossbound = ((int)sqrt((double)P)-1)/2;
	for (int i = 1; i <= crossbound; i++)
		if (!sieve[i])
			for (int j = 2*i*(i+1); j <= sievebound; j += 2*i+1)
				sieve[j] = 1;
}

int main()
{
	getPrimes();
	for (int i = 35; i < P; i += 2) {
		if (!sieve[(i-1)/2]) continue;
		bool flag = true;
		for (int sqr = 1; flag && 2*sqr*sqr < i; sqr++)
			if (!sieve[(i-2*sqr*sqr-1)/2])
				flag = false;
		if (flag) {
			cout << i << "\n";
			break;
		}
	}
}