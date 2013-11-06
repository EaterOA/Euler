#include <iostream>
#include <queue>

using namespace std;

#define ARRSIZE 1000000

int steps[ARRSIZE];

int findSteps(long long n)
{
	int nSteps = 0;
	while (true) {
		if (n % 2)
			n = n * 3 + 1;
		else
			n /= 2;
		nSteps++;
		if (n < ARRSIZE && steps[n]) {
			nSteps += steps[n];
			break;
		}
	}
	return nSteps;
}

int main()
{
	queue<int> qN; qN.push(1);
	queue<int> qS; qS.push(0);
	while (!qN.empty()) {
		int n = qN.front(); qN.pop();
		int s = qS.front(); qS.pop();
		if (n*2 < ARRSIZE && !steps[n*2]) {
			steps[n*2] = s+1;
			qN.push(n*2);
			qS.push(s+1);
		}
		if ((n-1)%3 == 0 && !steps[(n-1)/3] && (n-1)/3 > 1) {
			steps[(n-1)/3] = s+1;
			qN.push((n-1)/3);
			qS.push(s+1);
		}
	}
	int maxSteps = 0, maxStepsNum = -1;
	for (int n = 2; n < ARRSIZE; n++) {
		if (!steps[n])
			steps[n] = findSteps(n);
		if (steps[n] > maxSteps) {
			maxSteps = steps[n];
			maxStepsNum = n;
		}
	}
	cout << maxStepsNum << endl;
}