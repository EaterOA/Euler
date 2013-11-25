#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int sum = 0;
	for (int N = 1; N <= 10000; N++) {
		//Checking if N is perfect square
		double dRoot = sqrt((double)N);
		int firstRoot = (int)dRoot;
		if (dRoot == firstRoot) continue;
		//Counting period
		int i = 1;
		for (int root = firstRoot, bot = 1;; i++) {
			bot = (N - root*root) / bot;
			root = firstRoot - (root + firstRoot) % bot;
			if (bot == 1) break;
		}
		if (i % 2 == 1) sum++;
	}
	cout << sum << "\n";
}