#include <iostream>
#include <string>

using namespace std;

int main()
{
	string solution;
	for (int num = 9999; solution.size() == 0; num--) {
		int used = 1;
		string concat;
		for (int n = 1; concat.size() < 9; n++) {
			concat.append(to_string((long long)num*n));
			for (int tempNum = num*n; tempNum > 0; tempNum /= 10) {
				if (1 << (tempNum % 10) & used)
					goto out;
				else
					used += 1 << (tempNum % 10);
			}
		}
		if (used == (1 << 10) - 1)
			solution = concat;
		out:;
	}
	cout << solution << "\n";
}