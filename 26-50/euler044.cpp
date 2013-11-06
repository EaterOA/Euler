#include <iostream>
#include <math.h>

using namespace std;

#define N 5000

bool isPent(int p);

int main()
{
	int pent[N];
	for (int n = 0; n < N; n++) {
		pent[n] = (n+1) * (3*(n+1)-1) / 2;
	}
	int lowestD = (1<<31)-1;
	for (int d = 1; d < N && pent[d]-pent[0] < lowestD; d++) {
		for (int m = 0; m+d < N && pent[m+d]-pent[m] < lowestD; m++) {
			if (isPent(pent[m+d]-pent[m]) && isPent(pent[m+d]+pent[m])) {
				lowestD = pent[m+d]-pent[m];
			}
		}
	}
	cout << lowestD << endl;
}

bool isPent(int p)
{
	double n = sqrt(24*p + 1.) + 1;
	return (n == (int)n && (int)n % 6 == 0);
}
