#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const int DENOM = 7;
const int RMAP[DENOM][2] = {{'I', 1},
                            {'V', 5},
                            {'X', 10},
                            {'L', 50},
                            {'C', 100},
                            {'D', 500},
                            {'M', 1000}};

inline int r2n(char r)
{
    for (int i = 0; i < DENOM; i++)
        if (r == RMAP[i][0])
            return RMAP[i][1];
    return 0;
}

int get_value(const string& s)
{
    int value = 0;
    for (int i = 0; i < s.size(); i++) {
        int curn = r2n(s[i]);
        int nextn = i+1 < s.size() ? r2n(s[i+1]) : 0;
        if (curn < nextn) {
            value += nextn - curn;
            i++;
        }
        else
            value += curn;
    }
    return value;
}

string get_roman(int value)
{
    stringstream roman;
    while (value > 0) {
        for (int i = DENOM-1; i >= 0; i--) {
            int sub = i-1-(i+1)%2;
            if (value >= RMAP[i][1]) {
                value -= RMAP[i][1];
                roman << (char)RMAP[i][0];
                break;
            }
            else if (value >= RMAP[i][1]-RMAP[sub][1]) {
                value -= RMAP[i][1]-RMAP[sub][1];
                roman << (char)RMAP[sub][0] << (char)RMAP[i][0];
                break;
            }
        }
    }
    return roman.str();
}

int main()
{
    ifstream fin("roman.txt");
    if (!fin) {
        cerr << "Cannot open roman.txt!\n";
        return 1;
    }
    string s;
    int sum = 0;
    while (fin >> s) {
        int value = get_value(s);
        string roman = get_roman(value);
        sum += s.size() - roman.size();
    }
    cout << sum << endl;
}
