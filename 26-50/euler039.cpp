#include <iostream>
#include <math.h>

using namespace std;

#define N 1000

int main()
{
	int freq[N+1] = {0};
	for (int a = 2; a < N/3; a++) {
		for (int b = a + 1; b < (N - a)/2; b++) {
			double c = sqrt(double(a*a+b*b));
			if ((int)c == c)
				freq[a+b+(int)c]++;
		}
	}
	int max = 0;
	for (int n = 1; n <= N; n++)
		if (freq[n] > freq[max])
			max = n;
	cout << max << "\n";
}