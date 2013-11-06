#include <iostream>
#include <map>
#include <list>

using namespace std;

struct Permutation {
	char digits[10];
	Permutation(long long num)
	{
		memset(digits, 0, sizeof(digits));
		for (; num > 0; num /= 10) digits[num % 10]++;
	}
};

bool operator<(const Permutation &p1, const Permutation &p2)
{
	for (int d = 0; d < 10; d++) {
		if (p1.digits[d] < p2.digits[d]) return true;
		if (p1.digits[d] > p2.digits[d]) return false;
	}
	return false;
}

int main()
{
	map<Permutation, list<long long> > m;
	for (long long base = 1;; base++) {
		Permutation newPerm(base*base*base);
		m[newPerm].push_back(base);
		if (m[newPerm].size() == 5) {
			long long c = m[newPerm].front();
			cout << c*c*c << "\n";
			break;
		}
	}
}