#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>

using namespace std;

#define MAX 10000000

vector<int> primes, list;
double minR = 1000000;
int minN = 0;

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

bool isPerm(int n1, int n2)
{
	char arr[10] = {0}, zero[10] = {0};
	for (; n1 > 0; n1 /= 10) arr[n1%10]++;
	for (; n2 > 0; n2 /= 10) arr[n2%10]--;
	return !memcmp(arr, zero, 10);
}

bool isPerm2(int n1, int n2)
{
	//Replacing 10-element array with an int, 3 bits per number
	//It's faster!
	int arr1 = 0, arr2 = 0;
	for (; n1 > 0; n1 /= 10) arr1 += 1<<(n1%10*3);
	for (; n2 > 0; n2 /= 10) arr2 += 1<<(n2%10*3);
	return arr1==arr2;
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

bool chain(int idx, long long n, int depth)
{
	n *= primes[idx];
	if (n >= MAX) return 1;
	list.push_back(primes[idx]);
	if (depth == 0) {
		int totient = getTotient();
		if (isPerm2(n, totient) && double(n)/totient < minR) {
			minR = double(n)/totient;
			minN = n;
		}
	}
	else if (!chain(idx++, n, depth-1)) {
		int size = primes.size();
		for (; idx < size; idx++) 
			if (chain(idx, n, depth-1))
				break;
	}
	list.pop_back();
	return 0;
}

int main()
{
	primes = getPrimes(MAX/2);
	int size = primes.size();
	for (int i = 0; minN == 0; i++)
		for (int j = 0; j < size; j++)
			chain(j, 1, i);
	cout << minN << "\n";
}
