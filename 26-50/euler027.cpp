#include <iostream>
#include <vector>

using namespace std;

#define A 1000
#define B 1000

vector<int> primes;

void getPrimes();
bool isPrime(int n);

int main()
{
	getPrimes();
	int longest = 1, product = 0;
	for (int p = 0; p < primes.size(); p++) {
		int b = primes[p];
		for (int a = 1 - b; a < A; a++) {
			int n = 0;
			while (isPrime(n*n + a*n + b))
				n++;
			if (n > longest) {
				longest = n;
				product = a * b;
			}
		}
	}
	cout << product << "\n";
}

#define sqrt(n) int(sqrt(double(n)))
#define P 1000

bool isPrime(int n)
{
	if (n < 2) return false;
	for (int p = 0; p < primes.size() && primes[p] * primes[p] <= n; p++)
		if (n % primes[p] == 0)
			return false;
	return true;
}

void getPrimes()
{
	int sievebound = (P-1)/2;
	int calcbound = (sqrt(P)-1)/2;
	bool sieve[(P-1)/2+1] = {0};
	for (int i = 1; i <= calcbound; i++)
		if (!sieve[i])
			for (int j = 2*i*(i+1); j <= sievebound; j += 2*i+1)
				sieve[j] = 1;
	for (int i = 1; i <= sievebound; i++)
		if (!sieve[i])
			primes.push_back(2*i+1);
}