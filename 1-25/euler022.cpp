#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> nameList;
	ifstream fin("names.txt");
	for (string s; fin >> s;)
		nameList.push_back(s);
	sort(nameList.begin(), nameList.end());
	int sum = 0;
	for (int n = 0; n < nameList.size(); n++)
		for (int c = 0; c < nameList[n].size(); c++)
			sum += (nameList[n][c] - 'A' + 1) * (n + 1);
	cout << sum << "\n";
}
