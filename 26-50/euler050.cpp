#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define P 1000000

vector<int> primes;
bool sieve[(P-1)/2+1];

void getPrimes()
{
	int sievebound = (P-1)/2;
	int crossbound = ((int)sqrt((double)P)-1)/2;
	for (int i = 1; i <= crossbound; i++)
		if (!sieve[i])
			for (int j = 2*i*(i+1); j <= sievebound; j += 2*i+1)
				sieve[j] = 1;
	primes.push_back(2);
	for (int i = 1; i <= sievebound; i++)
		if (!sieve[i])
			primes.push_back(2*i+1);
}

int main()
{
	getPrimes();
	vector<long long> runSum(primes.size(), 0);
	int maxRun = 0;
	for (int p = 1; p < primes.size(); p++) {
		runSum[p] = runSum[p-1] + primes[p-1];
		if (maxRun == 0 && runSum[p] > P)
			maxRun = p-1;
	}
	for (int r = maxRun; r > 0; r--) {
		for (int l = 0;; l++) {
			long long next = runSum[l+r]-runSum[l];
			if (next > P) break;
			if (next % 2 && !sieve[(next-1)/2]) {
				cout << next << "\n";
				return 0;
			}
		}
	}
}