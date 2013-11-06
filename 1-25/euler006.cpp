#include <iostream>
#define abs(n) (n<0?-(n):n)

int main()
{
	int sumSq = 0;
	for (int n = 1; n <= 100; n++)
		sumSq += n * n;
	int sqSum = 50 * 101;
	sqSum *= sqSum;
	std::cout << abs(sumSq - sqSum) << "\n";
}