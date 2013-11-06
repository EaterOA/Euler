#include <iostream>

using namespace std;

const int primes[] = {2,3,5,7,11,13,17};
long long sum = 0;

void move(int depth, int cur, int used, long long full);

int main()
{
	for (int n = 0; n < 100; n++) {
		if (n/10 == n%10) continue;
		move(2, n*10, (1<<n/10) + (1<<n%10), n);
	}
	cout << sum << endl;
}

void move(int depth, int cur, int used, long long full)
{
	if (depth == 9) {
		for (int n = 0; n < 10; n++) {
			if (used & (1 << n)) continue;
			sum += full + n * 1000000000LL;
			return;
		}
	}
	for (int n = 0; n < 10; n++) {
		if (used & (1 << n)) continue;
		if ((cur + n) % primes[depth-2] == 0) {
			move(depth + 1, (cur % 100 + n)*10, used + (1 << n), full * 10 + n);
		}
	}
}