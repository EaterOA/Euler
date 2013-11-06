#include <iostream>

bool lyc[10000];

unsigned long long getOpp(unsigned long long cur)
{
	unsigned long long opposite = 0;
	for (unsigned long long tempCur = cur; tempCur > 0; tempCur /= 10)
		opposite = opposite * 10 + tempCur % 10;
	return opposite;
}

bool isLyc(int depth, unsigned long long cur)
{
	if (depth >= 50) return true;
	if (cur < 10000 && !lyc[cur]) return false;
	unsigned long long opposite = getOpp(cur);
	if (opposite == cur) return false;
	bool result = isLyc(depth+1, cur+opposite);
	if (cur < 10000) {
		lyc[cur] = result;
		lyc[opposite] = result;
	}
	return result;
}

int main()
{
	int count = 0;
	memset(lyc, 1, 10000);
	for (int n = 0; n < 10000; n++) {
		lyc[n] = isLyc(1, n+getOpp(n));
		if (lyc[n]) count++;
	}
	std::cout << count << "\n";
}