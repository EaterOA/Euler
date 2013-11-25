#include <iostream>
#include <cstring>

bool check(int num)
{
	int digits[10] = {0}, mDigits[10];
	for (int tempNum = num; tempNum > 0; tempNum /= 10) digits[tempNum%10]++;
	for (int multi = 2; multi <= 6; multi++) {
		memcpy(mDigits, digits, 4*10);
		for (int tempNum = multi*num; tempNum > 0; tempNum /= 10)
			if (mDigits[tempNum%10]-- == 0)
				return false;
	}
	return true;
}

int main()
{
	int cur = 10;
	for (int d = 2;; d++, cur *= 10) {
		for (int n = cur; n <= (cur*10)/6; n++) {
			if (check(n)) {
				std::cout << n << "\n";
				return 0;
			}
		}
	}
}