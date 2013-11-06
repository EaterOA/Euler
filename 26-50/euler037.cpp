#include <iostream>
#include <vector>

using namespace std;

#define P 1000000

vector<int> primes;
char sieve[P+1];

void getPrimes();
int cut(int n, bool right);

int main()
{
	getPrimes();
	int sum = 0;
	for (int p = 0; p < primes.size(); p++) {
		if (primes[p] < 10) {
			sieve[primes[p]] = 5;
			continue;
		}
		int left = cut(primes[p], 0);
		int right = cut(primes[p], 1);
		if (sieve[left] == 2 || sieve[left] == 5)
			sieve[primes[p]] += 2;
		if (sieve[right] == 3 || sieve[right] == 5)
			sieve[primes[p]] += 3;
		if (sieve[primes[p]] == 5)
			sum += primes[p];
	}
	cout << sum << "\n";
}

int cut(int n, bool right)
{
	if (right) return n / 10;
	int place = 1;
	for (int tempN = n; tempN > 9; tempN /= 10) place *= 10;
	while (n > place) n -= place;
	return n;
}

void getPrimes()
{
	int sievebound = P;
	int crossbound = sqrt((double)P);
	for (int j = 4; j <= sievebound; j += 2)
		sieve[j] = 1;
	for (int i = 3; i <= crossbound; i++)
		if (!sieve[i])
			for (int j = i*i; j <= sievebound; j += i)
				sieve[j] = 1;
	for (int i = 2; i <= sievebound; i++)
		if (!sieve[i])
			primes.push_back(i);
}