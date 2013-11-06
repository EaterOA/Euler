#include <iostream>

#define N 21

int main()
{
	long long grid[N][N] = {0};
	grid[0][0] = 1;
	for (int n = 1; n < N; n++) {
		for (int r = 0; r <= n; r++) {
			grid[r][n] = (r>0 ? grid[r-1][n] : 0) + grid[r][n-1];
			grid[n][r] = grid[r][n];
		}
	}
	std::cout << grid[N-1][N-1] << "\n";
}