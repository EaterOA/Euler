#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>

using namespace std;

#define MAX 1000000

vector<int> primes, list;
long long sum = 0;

vector<int> getPrimes(int P)
{
	if (P < 2) return vector<int>();
	vector<int> p;
	int sievebound = (P-1)/2;
	int crossbound = ((int)sqrt((double)P)-1)/2;
	bool *sieve = new bool[(P-1)/2+1];
	for (int n = 0; n < (P-1)/2+1; n++) sieve[n] = 0;
	for (int i = 1; i <= crossbound; i++)
		if (!sieve[i])
			for (int j = 2*i*(i+1); j <= sievebound; j += 2*i+1)
				sieve[j] = 1;
	p.push_back(2);
	for (int i = 1; i <= sievebound; i++)
		if (!sieve[i])
			p.push_back(2*i+1);
	delete [] sieve;
	return p;
}

int getTotient()
{
	int n = 1, res = list[0]-1;
	int size = list.size();
	for (int i = 1; i < size; i++) {
		if (list[i] == list[i-1]) n *= list[i];
		else res *= list[i]-1;
	}
	return n*res;
}

bool chain(int idx, long long n)
{
	n *= primes[idx];
	if (n > MAX) return 1;
	list.push_back(primes[idx]);
	sum += getTotient();
	int size = primes.size();
	for (; idx < size; idx++) 
		if (chain(idx, n))
			break;
	list.pop_back();
	return 0;
}

int main()
{
	primes = getPrimes(MAX);
	int size = primes.size();
	for (int j = 0; j < size; j++)
		chain(j, 1);
	cout << sum << "\n";
}
