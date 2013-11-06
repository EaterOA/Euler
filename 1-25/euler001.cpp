#include <iostream>
#define LIMIT (1000-1)

int main()
{
	int sum = 0;
	sum += 3 * (LIMIT/3+1) * (LIMIT/3) / 2;
	sum += 5 * (LIMIT/5+1) * (LIMIT/5) / 2;
	sum -= 15 * (LIMIT/15+1) * (LIMIT/15) / 2;
	std::cout << sum << "\n";
}