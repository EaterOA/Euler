#include <iostream>
#include <set>

using namespace std;

bool setDigits(bool used[], int n)
{
	for (; n > 0; n /= 10) {
		if (used[n % 10])
			return false;
		used[n % 10] = 1;
	}
	return true;
}

int main()
{
	set<int> s;
	for (int n = 2; n < 100; n++) {
		bool used[10] = {1};
		if (!setDigits(used, n)) continue;
		int start = 1000;
		if (n > 9) start = 100;
		bool used2[10];
		for (int m = start; m * n < 10000; m++) {
			memcpy(used2, used, 10);
			if (setDigits(used2, m) && setDigits(used2, m*n))
				s.insert(m*n);
		}
	}
	int sum = 0;
	for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++)
		sum += *iter;
	cout << sum << "\n";
}