#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	//All hexagonal numbers are also triangle numbers, so no need
	//to check triangularity
	for (long long h = 144;; h++) {
		long long hex = h * (2*h - 1);
		double pentID = (sqrt(24*hex + 1.) + 1) / 6;
		if (pentID == (int)pentID) {
			cout << hex << endl;
			break;
		}
	}
}