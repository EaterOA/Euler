#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define P 1000

bool fourDisc[P*P+1];
vector<int> primes;

void getPrimes();
void permutate(int depth, int product, int unused);

int main()
{
	getPrimes();
	permutate(primes.size(), 1, 4);
	for (int n = 1, count = 0; n <= P*P; n++) {
		if (!fourDisc[n])
			count = 0;
		else
			count++;
		if (count == 4) {
			cout << n - 3 << "\n";
			break;
		}
	}
}

void permutate(int depth, int product, int unused)
{
	if (unused > depth || product > P*P) return;
	if (unused == 0) {
		fourDisc[product] = 1;
		return;
	}
	permutate(depth - 1, product, unused);
	while (product <= P*P) {
		product *= primes[depth - 1];
		permutate(depth - 1, product, unused - 1);
	}
}

void getPrimes()
{
	int sievebound = (P-1)/2;
	int crossbound = ((int)sqrt((double)P)-1)/2;
	bool sieve[(P-1)/2+1] = {0};
	for (int i = 1; i <= crossbound; i++)
		if (!sieve[i])
			for (int j = 2*i*(i+1); j <= sievebound; j += 2*i+1)
				sieve[j] = 1;
	primes.push_back(2);
	for (int i = 1; i <= sievebound; i++)
		if (!sieve[i])
			primes.push_back(2*i+1);
}