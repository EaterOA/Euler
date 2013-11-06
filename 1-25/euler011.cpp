#include <iostream>
#include <fstream>

using namespace std;

int grid[20][20];

int multiply(int r, int c, int dR, int dC)
{
	int product = 1;
	for (int n = 0; n < 4; n++, r += dR, c += dC) {
		product *= grid[r][c];
	}
	return product;
}

int main()
{
	ifstream fin("euler011.txt");
	for (int r = 0; r < 20; r++)
		for (int c = 0; c < 20; c++)
			fin >> grid[r][c];

	int greatest = 0;
	for (int r = 0; r < 20; r++) {
		for (int c = 0; c < 20; c++) {
			if (r < 16 && multiply(r,c,1,0) > greatest)
				greatest = multiply(r,c,1,0);
			if (c < 16 && multiply(r,c,0,1) > greatest)
				greatest = multiply(r,c,0,1);
			if (r < 16 && c < 16 && multiply(r,c,1,1) > greatest)
				greatest = multiply(r,c,1,1);
			if (r >= 3 && c < 16 && multiply(r,c,-1,1) > greatest)
				greatest = multiply(r,c,-1,1);
		}
	}
	cout << greatest << endl;
}