#include <iostream>
#include <string>

using namespace std;

int main()
{
	int prod = 1, d = 0, nextPow = 1;
	for (int n = 1; d < 1000000; n++) {
		string digits = to_string((long long)n);
		d += digits.size();
		if (d < nextPow) continue;
		prod *= digits[digits.size() - d + nextPow - 1] - '0';
		nextPow *= 10;
	}
	cout << prod << "\n";
}