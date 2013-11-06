#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("euler013.txt");
	string num[100];
	for (int n = 0; n < 100; n++)
		getline(fin, num[n]);
	string sum(15, '\0');
	for (int n = 0; n < sum.size() - 2; n++) {
		int tSum = 0;
		for (int m = 0; m < 100; m++)
			tSum += num[m][n]-'0';
		sum[n] += tSum/100;
		sum[n+1] += tSum/10%10;
		sum[n+2] += tSum%10;
	}
	for (int n = sum.size() - 1; n > 0; n--) {
		if (sum[n] >= 10) {
			sum[n] -= 10;
			sum[n-1]++;
		}
	}
	for (int n = 0; n < 10; n++)
		cout << int(sum[n]);
	cout << "\n";
}
