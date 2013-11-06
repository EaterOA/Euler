#include <iostream>

using namespace std;

#define N 7 //8- and 9-digit numbers are divisible by 3

bool isPrime(int n);
bool permutate(int depth, int used, int curNum);

int main()
{
	permutate(N, 0, 0);
}

bool isPrime(int n)
{
	for (int p = 2; p*p <= n; p++) {
		if (n % p == 0) return false;
	}
	return true;
}

bool permutate(int depth, int used, int curNum)
{
	if (depth == 0 && isPrime(curNum)) {
		cout << curNum << endl;
		return true;
	}
	for (int n = N-1; n >= 0; n--) {
		if (used & (1 << n)) continue;
		if (permutate(depth - 1, used + (1 << n), curNum * 10 + n + 1)) return true;
	}
	return false;
}