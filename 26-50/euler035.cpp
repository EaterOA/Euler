#include <iostream>
#include <vector>

using namespace std;

#define N 1000000

bool sieve[(N-1-1)/2+1];
vector<int> primes;

void getPrimes();
bool all1379(int n);
int rotate(int n);
int sumRotation(int n);

int main()
{
	getPrimes();
	int sum = 0;
	for (int p = 0; p < primes.size(); p++) {
		if (sieve[(primes[p]-1)/2] || primes[p] >= 10 && !all1379(primes[p])) continue;
		bool flag = 1;
		for (int next = rotate(primes[p]); next != primes[p] && flag; next = rotate(next)) {
			flag = 0;
			if (!sieve[(next-1)/2]) {
				flag = 1;
				sieve[(next-1)/2] = 1;
			}
		}
		if (!flag) continue;
		sum += sumRotation(primes[p]);
	}
	cout << sum << "\n";
}

int sumRotation(int n)
{
	int sum = 1, next = rotate(n);
	while (next != n) {
		sum++;
		next = rotate(next);
	}
	return sum;
}

int rotate(int n)
{
	int product = n % 10;
	for (int tempN = n/10; tempN != 0; tempN /= 10)
		product *= 10;
	return product + n/10;
}

bool all1379(int n)
{
	while (n > 0) {
		if (n % 2 == 0 || n % 5 == 0) return false;
		n /= 10;
	}
	return true;
}

void getPrimes()
{
	int P = N-1;
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