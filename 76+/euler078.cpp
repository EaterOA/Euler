#include <iostream>

using namespace std;

#define EULER

int main()
{
	const int mod = 1000000;
	const int depth = 75000;

#ifdef EULER
	//Euler's generating function for partitions. O(n^1.5)
	int idx1[1001], idx2[1001];
	for (int i = 1; i <= 1000; i++) {
		idx1[i] = i*(3*i - 1)/2;
		idx2[i] = i*(3*i + 1)/2;
	}
	long long p[depth+1] = {1};
	for (int i = 1;; i++) {
		long long next = 0;
		for (int j = 1; j <= i; j++) {
			int n1 = i - idx1[j];
			if (n1 < 0) break;
			next += (j & 1) ? p[n1] : -p[n1];
			int n2 = i - idx2[j];
			if (n2 < 0) break;
			next += (j & 1) ? p[n2] : -p[n2];
		}
		next %= mod;
		if (!next) {
			cout << i << endl;
			break;
		}
		p[i] = next;
	}

#else
	//DP way. O(n^2) with alot of expensive moduli
	int arr[depth+1] = {1};
	for (int i = 1; i <= depth; i++) {
		for (int j = 0; j+i <= depth; j++) {
			arr[i+j] += arr[j];
			arr[i+j] %= mod;
		}
		if (!arr[i]) {
			cout << i << endl;
			break;
		}
	}
#endif
}