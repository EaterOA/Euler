#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define N 28123

bool summable[N];
vector<int> abundantNum;

int findSumOfDivisors(vector<int> &p, int num);
vector<int> findPrimes(int n);
bool isPrime(vector<int> &p, int num);

int main()
{
	vector<int> pList = findPrimes(N/2);
	int sum = 0;
	for (int a = 1; a < N; a++) {
		int b = findSumOfDivisors(pList, a) - a;
		if (b > a) {
			abundantNum.push_back(a);
			for (int i = 0; i < abundantNum.size() && abundantNum[i] + a < N; i++)
				summable[abundantNum[i] + a] = 1;
		}
		if (!summable[a])
			sum += a;
	}
	cout << sum << "\n";
}

int findSumOfDivisors(vector<int> &p, int num)
{
	int sum = 1;
	for (int n = 0; p[n]*p[n] <= num && num > 1; n++) {
		if (num % p[n] == 0) {
			int multiplier = p[n] + 1;
			num /= p[n];
			for (int curP = p[n]; num % p[n] == 0; num /= p[n]) {
				curP *= p[n];
				multiplier += curP;
			}
			sum *= multiplier;
		}
	}
	if (num > 1)
		sum *= num + 1;
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