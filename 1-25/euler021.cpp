#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define N 10000

int findSumOfDivisors(vector<int> &p, int num);
vector<int> findPrimes(int n);
bool isPrime(vector<int> &p, int num);

int main()
{
	vector<int> pList = findPrimes(N/2);
	int sum = 0;
	for (int a = 1; a < N; a++) {
		int b = findSumOfDivisors(pList, a) - a;
		if (b <= a) continue;
		if (a == findSumOfDivisors(pList, b) - b)
			sum += a + b;
	}
	cout << sum << "\n";
}

int findSumOfDivisors(vector<int> &p, int num)
{
	vector<int> usedP(p.size(), 0);
	for (int n = 0; n < p.size() && num > 1; n++)
		for (; num % p[n] == 0; num /= p[n])
			usedP[n]++;
	int sum = 1;
	for (int n = 0; n < p.size(); n++) {
		int multiplier = 1;
		for (int m = 0; m < usedP[n]; m++)
			multiplier += (int)pow(p[n], m+1.0);
		sum *= multiplier;
	}
	return sum;
}

vector<int> findPrimes(int num)
{
	vector<int> p;
	if (num >= 2) p.push_back(2);
	if (num >= 3) p.push_back(3);
	for (int m = 6; m <= num + 1; m += 6) {
		if (isPrime(p, m-1))
			p.push_back(m-1);
		if (m+1 <= num && isPrime(p, m+1))
			p.push_back(m+1);
	}
	return p;
}

bool isPrime(vector<int> &p, int num)
{
	for (int n = 0; n < p.size() && p[n]*p[n] <= num; n++)
		if (num % p[n] == 0)
			return false;
	return true;
}