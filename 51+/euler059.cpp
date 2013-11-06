#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

bool find(char str[], int size, string target)
{
	for (int c = 0; c < size-target.size(); c++) {
		bool flag = 1;
		for (int d = 0; flag && d < target.size(); d++)
			if (str[c+d] != target[d])
				flag = 0;
		if (flag)
			return true;
	}
	return false;
}

int main()
{
	ifstream fin("cipher1.txt");
	vector<char> encrypted;
	for (char s[5]; fin.getline(s, 4, ',');)
		encrypted.push_back(atoi(s));
	char* decrypted = new char[encrypted.size()];
	int sum = 0;
	//Slower than frequency analysis, but simple
	for (int k = 1; k < 26*26*26; k++) {
		char key[] = {k/26/26+'a', k/26%26+'a', k%26+'a'};
		int pos = 0, c;
		for (c = 0; c < encrypted.size(); c++) {
			decrypted[c] = encrypted[c]^key[pos];
			if (decrypted[c] < 32 || decrypted[c] > 126) break;
			pos = (pos + 1) % 3;
		}
		if (c != encrypted.size()) continue;
		if (find(decrypted, encrypted.size(), " and ")) {
			for (int c = 0; c < encrypted.size(); c++)
				sum += decrypted[c];
			break;
		}
	}
	cout << sum << "\n";
	delete [] decrypted;
}