#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define sqrt(n) int(sqrt(double(n)))
#define P 1000

vector<int> primes;

void findPrimes()
{
	int sievebound = (P-1)/2;
	int calcbound = (sqrt(P)-1)/2;
	bool sieve[(P-1)/2+1] = {0};
	for (int i = 1; i <= calcbound; i++)
		if (!sieve[i])
			for (int j = 2*i*(i+1); j <= sievebound; j += 2*i+1)
				sieve[j] = 1;
	if (P > 2) primes.push_back(2);
	for (int i = 1; i <= sievebound; i++)
		if (!sieve[i])
			primes.push_back(2*i+1);
}

int main()
{
	findPrimes();
	int longest = 0, longestD;
	for (int p = primes.size() - 1; p >= 0 && primes[p] > longest; p--) {
		bool index[P] = {0};
		for (int i = 1, n = 1, d = primes[p]; n > 0; i++) {
			if (index[n] == 0)
				index[n] = 1;
			else {
				if (i > longest) {
					longest = i;
					longestD = d;
				}
				break;
			}
			n = (n * 10) % d;
		}
	}
	cout << longestD << "\n";
}
