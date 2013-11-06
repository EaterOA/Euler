#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define N 2000000

vector<int> p;

bool isprime(int n)
{
	double sq = sqrt(double(n));
	for (int i = 0; i < p.size() && p[i] <= sq; i++)
		if (n % p[i] == 0)
			return false;
	return true;
}

int main()
{
	p.push_back(2);
	p.push_back(3);
	long long sum = 5;
	for (int n = 6; n < N; n += 6) {
		if (isprime(n-1)) {
			sum += n-1;
			p.push_back(n-1);
		}
		if (n+1 < N && isprime(n+1)) {
			sum += n+1;
			p.push_back(n+1);
		}
	}
	cout << sum << endl;
}
