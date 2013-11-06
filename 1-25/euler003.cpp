#include <iostream>

int main()
{
	long long num = 600851475143;
	for (int n = 3; n < num; n++)
		while (num % n == 0)
			num /= n;
	std::cout << num << "\n";
}