#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void permutate(int d, int used, vector<int> &order, vector<vector<int> > &set)
{
	if (d == 5) {
		set.push_back(order);
		return;
	}
	for (int o = 0; o < 5; o++) {
		if ((used & (1<<o)) == 0) {
			order.push_back(o);
			permutate(d+1, used + (1<<o), order, set);
			order.pop_back();
		}
	}
}

int main()
{
	vector<vector<int> > perm;
	permutate(0, 0, vector<int>(), perm);
	int outside[] = {6,7,8,9,10};
	int inside[] = {1,2,3,4,5};
	int lineSum = (55+15)/5;
	for (int i = 0; i < perm.size(); i++) {
		if (outside[perm[i][0]] != 6) continue;
		for (int j = 0; j < perm.size(); j++) {
			bool satisfy = true;
			for (int line = 0; line < 5 && satisfy; line++)
				satisfy = outside[perm[i][line]] + inside[perm[j][line]] + inside[perm[j][(line+6)%5]] == lineSum;
			if (!satisfy) continue;
			stringstream config;
			for (int line = 0; line < 5; line++)
				config << outside[perm[i][line]] << inside[perm[j][line]] << inside[perm[j][(line+6)%5]];
			cout << config.str() << "\n";
		}
	}
}