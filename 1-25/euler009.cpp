#include <iostream>
#define N 1000

int main()
{
	for (int a = 1; a < N/3; a++)
		for (int b = a+1; b < (N-a) / 2; b++) {
			int c = N-a-b;
			if (c < a+b && a*a + b*b == c*c) {
				std::cout << a*b*c << "\n";
				return 0;
			}
		}
}
