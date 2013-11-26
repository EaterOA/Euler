#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>

using namespace std;

#define LIMIT 1000
#define MAXN 5000

vector<int> getPrimes(int P)
{
	vector<int> primes;
	int sievebound = (P-1)/2;
	int crossbound = ((int)sqrt((double)P)-1)/2;
	bool *sieve = new bool[(P-1)/2+1];
    memset(sieve, 0, (P-1)/2+1);
	for (int i = 1; i <= crossbound; i++)
		if (!sieve[i])
			for (int j = 2*i*(i+1); j <= sievebound; j += 2*i+1)
				sieve[j] = 1;
	primes.push_back(2);
	for (int i = 1; i <= sievebound; i++)
		if (!sieve[i])
			primes.push_back(2*i+1);
	delete [] sieve;
	return primes;
}

int main()
{
	//Manually raise limit or dump it in a loop until the result is found
	vector<int> primes = getPrimes(LIMIT);
	int ways[LIMIT] = {0};
	ways[0] = 1;
	for (int i = 0; i < primes.size(); i++) {
		for (int j = 0; j + primes[i] < LIMIT; j++) {
			ways[j + primes[i]] += ways[j];
		}
		for (int j = (i>0 ? primes[i-1]+1 : 0); j <= primes[i]; j++) {
			if (ways[j] >= MAXN) {
				cout << j << endl;
				i = primes.size();
				break;
			}
		}
	}
}