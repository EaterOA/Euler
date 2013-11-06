#include <iostream>
#include <math.h>

using namespace std;

int curN = 0;
int primes[10000];

bool isPrime(int n);

int main()
{
	for (int n = 2;; n++) {
		if (isPrime(n)) {
			if (curN == 10000) {
				cout << n << endl;
				break;
			}
			primes[curN++] = n;
		}
	}
}

bool isPrime(int n)
{
	for (int p = 0; p < curN && primes[p] <= sqrt((double)n); p++)
		if (n % primes[p] == 0)
			return false;
	return true;
}