#include <iostream>

int firstTwenty[] = {3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8,6};
int tens[] = {3,6,6,5,5,5,7,6,6};
int hundred = 7;

int main()
{
	int sum = 0;
	for (int n = 1; n <= 999; n++) {
		if (n >= 100) {
			sum += firstTwenty[n/100-1];
			sum += hundred;
			if (n % 100)
				sum += 3;
			else
				continue;
		}
		if (n % 100 < 20)
			sum += firstTwenty[n%100-1];
		else {
			sum += tens[n/10%10-1];
			if (n % 10)
				sum += firstTwenty[n%10-1];
		}
	}
	sum += firstTwenty[0] + 8;
	std::cout << sum << "\n";
}