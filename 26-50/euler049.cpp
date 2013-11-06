#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define P 10000

bool sieve[(P-1)/2+1];
vector<int> primes;

void getPrimesOver1000();
void permutate(vector<int> &list, int unused[], int cur, int depth);

int main()
{
	getPrimesOver1000();
	for (int n = 0; n < primes.size(); n++) {
		if (sieve[(primes[n]-1)/2]) continue;
		//Find list of prime permutations of primes[n]
		vector<int> list;
		int unused[10] = {0};
		for (int tempP = primes[n]; tempP > 0; tempP /= 10)
			unused[tempP%10]++;
		permutate(list, unused, 0, 4);
		bool isPermPrime[P] = {0};
		for (int i = 0; i < list.size(); i++) {
			sieve[(list[i]-1)/2] = 1;
			isPermPrime[list[i]] = 1;
		}
		//Look for arithmetic series
		if (list.size() < 3 || primes[n] == 1487) continue;
		for (int i = 0; i < list.size()-2; i++) {
			for (int j = i+1; j < list.size()-1 && list[j]+list[j]-list[i] < P; j++) {
				if (isPermPrime[list[j]+list[j]-list[i]]) {
					cout << list[i] << " " << list[j] << " " << list[j]+list[j]-list[i] << "\n";
					return 0;
				}
			}
		}
	}
}

void permutate(vector<int> &list, int unused[], int cur, int depth)
{
	if (depth == 0) {
		if (cur > 1000 && cur % 2 && !sieve[(cur-1)/2]) list.push_back(cur);
		return;
	}
	for (int n = 0; n < 10; n++) {
		if (unused[n]) {
			unused[n]--;
			permutate(list, unused, cur*10 + n, depth - 1);
			unused[n]++;
		}
	}
}

void getPrimesOver1000()
{
	int sievebound = (P-1)/2;
	int crossbound = ((int)sqrt((double)P)-1)/2;
	for (int i = 1; i <= crossbound; i++)
		if (!sieve[i])
			for (int j = 2*i*(i+1); j <= sievebound; j += 2*i+1)
				sieve[j] = 1;
	for (int i = (1001-1)/2; i <= sievebound; i++)
		if (!sieve[i])
			primes.push_back(2*i+1);
}