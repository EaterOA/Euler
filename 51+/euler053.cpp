#include <iostream>

#define N 100

int main()
{
	long long answer = 0;
	for (int n = 23; n <= N; n++) {
		for (int r = 2, num = n; r <= n/2; r++) {
			num = num*(n+1-r)/r;
			if (num > 1000000) {
				answer = n+1-2*r;
				break;
			}
		}
	}
	std::cout << answer << "\n";
}