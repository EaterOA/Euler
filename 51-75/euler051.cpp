#include <iostream>
#include <vector>

using namespace std;

#define P 1000000

vector<int> primes;
bool sieve[(P-1)/2+1];

int getMax(int combi, int num);
void getPrimes();

int main()
{
	primes.reserve(P/6);
	getPrimes();
	for (int n = 4; n < primes.size(); n++) {
		int size = 0;
		for (int tempP = primes[n] / 10; tempP > 0; tempP /= 10) size++;
		for (int combi = 1; combi < (1 << size); combi++) {
			if (getMax(combi, primes[n]) == 8) {
				cout << primes[n] << "\n";
				return 0;
			}
		}
	}
}

int getMax(int combi, int num)
{
	int offset = 0, origDigit = -1;
	for (int multiplier = 10, shift = 0; combi >= (1 << shift); multiplier *= 10, shift++) {
		if ((1 << shift) & combi) {
			int digit = num / multiplier % 10;
			if (origDigit == -1) origDigit = digit;
			if (origDigit != digit) return 0;
			num -= digit * multiplier;
			offset += multiplier;
		}
	}
	int numPrimes = 1;
	for (int digit = origDigit+1; digit < 10; digit++) {
		if (sieve[(num+offset*digit)/2]) continue;
		numPrimes++;
	}
	return numPrimes;
}

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