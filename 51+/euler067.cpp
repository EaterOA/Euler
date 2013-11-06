#include <iostream>
#include <fstream>

using namespace std;

#define N 100
#define max(a,b) (a>b?a:b)

int main()
{
	ifstream fin("triangle.txt");
	int prev[N], cur[N];
	fin >> cur[0];
	for (int n = 2; n <= N; n++) {
		memmove(prev, cur, sizeof(cur));
		for (int m = 0; m < n; m++) {
			fin >> cur[m];
			if (m == 0) cur[m] += prev[m];
			else if (m == n - 1) cur[m] += prev[m-1];
			else cur[m] += max(prev[m],prev[m-1]);
		}
	}
	int highest = 0;
	for (int n = 0; n < N; n++)
		if (cur[n] > highest)
			highest = cur[n];
	cout << highest << "\n";
}