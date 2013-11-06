#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int *primeList;
int pSize;
bool **mat = new bool*[10000];

void getPrimes(int P)
{
	vector<int> primes;
	int sievebound = (P-1)/2;
	int crossbound = ((int)sqrt((double)P)-1)/2;
	bool *sieve = new bool[(P-1)/2+1];
	for (int n = 0; n < (P-1)/2+1; n++) sieve[n] = 0;
	for (int i = 1; i <= crossbound; i++)
		if (!sieve[i])
			for (int j = 2*i*(i+1); j <= sievebound; j += 2*i+1)
				sieve[j] = 1;
	for (int i = 2; i <= sievebound; i++)
		if (!sieve[i])
			primes.push_back(2*i+1);
	delete [] sieve;
	pSize = primes.size();
	primeList = new int[pSize];
	for (int i = 0; i < pSize; i++)
		primeList[i] = primes[i];
}

int concat(int n1, int n2)
{
	int offset = 1;
	for (int temp = n2; temp > 0; temp /= 10, offset *= 10);
	return n1 * offset + n2;
}

bool isPrime(int n)
{
	if (n % 2 == 0 || n % 3 == 0) return false;
	for (int p = 6; p*p < n; p += 6) {
		if (n % (p-1) == 0) return false;
		if (n % (p+1) == 0) return false;
	}
	return true;
}

char threeOffset(int n)
{
	int sum = 0;
	for (; n > 0; n /= 10) sum += n % 10;
	return sum % 3;
}

int main()
{
	getPrimes(10000);
	for (int n = 0; n < 10000; n++) mat[n] = new bool[10000];
	for (int p = 0; p < pSize-1; p++) {
		for (int q = p+1; q < pSize; q++) {
			if (isPrime(concat(primeList[p], primeList[q])) &&
			    isPrime(concat(primeList[q], primeList[p])))
				mat[primeList[p]][primeList[q]] = 1;
			else
				mat[primeList[p]][primeList[q]] = 0;
		}
	}
	vector<vector<int>*> sets[2];
	bool pflag = 1;
	for (int p = 0; p < pSize; p++) {
		char offset = threeOffset(primeList[p])-1;
		int size = sets[offset].size();
		for (int i = 0; i < size; i++) {
			bool flag = 1;
			for (int j = 0; flag && j < sets[offset][i]->size(); j++)
				if (!mat[sets[offset][i]->at(j)][primeList[p]])
					flag = 0;
			if (flag) {
				vector<int>* newSet = new vector<int>(*sets[offset][i]);
				newSet->push_back(primeList[p]);
				if (newSet->size() == 5) {
					int sum = 0;
					for (int j = 0; j < newSet->size(); j++)
						sum += newSet->at(j);
					cout << sum << "\n";
					pflag = 0;
					break;
				}
				sets[offset].push_back(newSet);
			}
		}
		if (pflag == 0) break;
		sets[offset].push_back(new vector<int>(1, primeList[p]));
	}
	for (int d = 0; d < sets[0].size(); d++) delete sets[0][d];
	for (int d = 0; d < sets[1].size(); d++) delete sets[1][d];
	for (int n = 0; n < 10000; n++) delete [] mat[n];
	delete mat;
}