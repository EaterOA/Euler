#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

long long hVal(string h[]);
int nOfAKind(int n, int pos, string h[]);
bool sameSuit(string h[]);
int straightValue(string h[]);
int cVal(char card);

int main()
{
	ifstream fin("poker.txt");
	int wins = 0;
	string hand1[5], hand2[5];
	for (int h = 0; h < 1000; h++) {
		for (int c = 0; c < 5; c++) {
			fin >> hand1[c];
			hand1[c][0] = cVal(hand1[c][0]);
		}
		for (int c = 0; c < 5; c++) {
			fin >> hand2[c];
			hand2[c][0] = cVal(hand2[c][0]);
		}
		sort(hand1, hand1+5);
		sort(hand2, hand2+5);
		if (hVal(hand1) > hVal(hand2)) wins++;
	}
	cout << wins << endl;
}

long long hVal(string h[])
{
	long long hValue = 0;
	hValue = 10*hValue + (sameSuit(h)?straightValue(h):0);
	hValue = 100*hValue + nOfAKind(4,1,h);
	hValue = 100*hValue + (nOfAKind(2,1,h)?nOfAKind(3,1,h):0);
	hValue = 10*hValue + sameSuit(h);
	hValue = 10*hValue + straightValue(h);
	hValue = 100*hValue + nOfAKind(3,1,h);
	hValue = 10*hValue + (bool)nOfAKind(2,2,h);
	hValue = 100*hValue + max(nOfAKind(2,1,h), nOfAKind(2,2,h));
	hValue = 100*hValue + h[4][0];
	return hValue;
}

int nOfAKind(int n, int pos, string h[])
{
	for (int i = 0; i < 5-n+1; i++) {
		int m = n-1;
		for (; i < 4; m--, i++)
			if (h[i][0] != h[i+1][0])
				break;
		if (m == 0 && --pos == 0)
			return h[i][0];
	}
	return 0;
}

bool sameSuit(string h[])
{
	for (int c = 0; c < 4; c++)
		if (h[c][1] != h[c+1][1])
			return false;
	return true;
}

int straightValue(string h[])
{
	for (int c = 0; c < 4; c++)
		if (h[c][0] != h[c+1][0]-1)
			return 0;
	return h[0][0];
}

int cVal(char card)
{
	if (card == 'T') return 9;
	if (card == 'J') return 10;
	if (card == 'Q') return 11;
	if (card == 'K') return 12;
	if (card == 'A') return 13;
	return card-'2'+1;
}