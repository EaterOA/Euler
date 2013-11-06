#include <iostream>
#include <math.h>

using namespace std;

#define N 1000

void add(char prev[], char cur[], char next[], int digits)
{
	for (int i = 0; i < digits; i++) {
		next[i] = prev[i] + cur[i] + next[i];
		if (next[i] > 9) {
			next[i] -= 10;
			next[i+1]++;
		}
	}
}

int main()
{
	//Brute force
	int digits = 1;
	char prev[N] = {0}, cur[N] = {1};
	for (int term = 2;; term++) {
		char next[N] = {0};
		add(prev, cur, next, digits);
		if (next[digits]) {
			digits++;
			if (digits == N) {
				cout << term << endl;
				break;
			}
		}
		memmove(prev, cur, N);
		memmove(cur, next, N);
	}
	//Binet's formula: phi^term / sqrt(5) > 10^(N-1)
	double phi = 1.61803398875;
	int term = (int)((log10(sqrt(5.0)) + N - 1)/log10(phi) + 0.5);
	cout << term << "\n";
}