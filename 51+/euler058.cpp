#include <iostream>

bool isPrime(int n)
{
	if (n % 2 == 0 || n % 3 == 0) return false;
	for (int p = 6; p*p < n; p += 6) {
		if (n % (p-1) == 0) return false;
		if (n % (p+1) == 0) return false;
	}
	return true;
}

int main()
{
	int length = 7;
	int topRight = 31, topLeft = 37, botLeft = 43;
	for (int nPrimes = 8, nTotal = 13; 10*nPrimes >= nTotal; length += 2, nTotal += 4) {
		topRight += 2 + (length-1)*4;
		topLeft += 4 + (length-1)*4;
		botLeft += 6 + (length-1)*4;
		if (isPrime(topRight)) nPrimes++;
		if (isPrime(topLeft)) nPrimes++;
		if (isPrime(botLeft)) nPrimes++;
	}
	std::cout << length << "\n";
}