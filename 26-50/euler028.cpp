#include <iostream>

#define N 1001

int main()
{
	//Brute force
	int sum = 1, value = 1;
	for (int sp = 1; sp < N; sp += 2) {
		for (int c = 0; c < 4; c++) {
			value += sp + 1;
			sum += value;
		}
	}
	std::cout << sum << "\n";
	//Algebra
	//Each corner number can be represented by formula: n^2 + (q-1)(n-1),
	//where n is the size of spiral, and q is the quadrant
	//n has step 2, so equation is translated with n = 2i + 1
	//Solution = sum(i=1-500)(16i^2 + 4i + 4) + 1
	//= 16(500)(501)(1001)/6 + 4(500)(501) + 4(500)/2 + 1
	std::cout << (16*500*501/6*1001 + 4*500*501/2 + 4*500/2 + 1) << "\n";
}