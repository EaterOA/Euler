#include <iostream>
#include <fstream>
#include <set>
#include <sstream>

using namespace std;

int main()
{
    set<int> digits[10];
    int in[10] = {0};
    bool seen[10] = {0};
    ifstream fin("keylog.txt");
    for (char w[4]; fin >> w;) {
        digits[w[0]-'0'].insert(w[1]-'0');
        digits[w[1]-'0'].insert(w[2]-'0');
        seen[w[0]-'0'] = seen[w[1]-'0'] = seen[w[2]-'0'] = 1;
    }
    for (unsigned i = 0; i < 10; i++)
        for (set<int>::iterator iter = digits[i].begin(); iter != digits[i].end(); iter++)
            in[*iter]++;
    //Topological sort
    stringstream ss;
    for (int src = -1;; src = -1) {
        for (unsigned i = 0; i < 10; i++)
            if (seen[i] && in[i] == 0)
                src = i;
        if (src == -1) break;
        in[src] = -1;
        ss << src;
        for (set<int>::iterator iter = digits[src].begin(); iter != digits[src].end(); iter++)
            in[*iter]--;
    }
    for (unsigned i = 0; i < 10; i++) {
        if (in[i] > 0) {
            cout << "Shit, need repeated digits\n";
            exit(0);
        }
    }
    cout << ss.str() << "\n";
}