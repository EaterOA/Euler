#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> primes;
	int prod = 1;
	for (int n = 2; n * prod <= 1000000; n++) {
		bool flag = 1;
		for (int p = 0; p < primes.size() && flag; p++)
			if (n % primes[p] == 0)
				flag = 0;
		if (flag) {
			primes.push_back(n);
			prod *= n;
		}
	}
	cout << prod << "\n";
}