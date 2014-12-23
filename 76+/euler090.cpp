#include <iostream>
#include <vector>

using namespace std;

const string rolls[] = {"01", "04", "09", "16", "25",
                        "36", "49", "64", "81"};

void find_combinations(vector<vector<char> >& all, vector<char>& cur, int d)
{
    if (cur.size() == 6) {
        all.push_back(cur);
        return;
    }
    for (int i = d; 10-i >= 6-cur.size(); i++) {
        cur.push_back(i+'0');
        find_combinations(all, cur, i+1);
        cur.pop_back();
    }
}

template <class T>
inline bool vfind(const vector<T>& v, T c)
{
    for (int i = 0; i < v.size(); i++)
        if (v[i] == c)
            return true;
    return false;
}

bool is_legal(const vector<char>& d1, const vector<char>& d2)
{
    for (int i = 0; i < 9; i++) {
        char c1 = rolls[i][0], c2 = rolls[i][1];
        if (vfind(d1, c1) && vfind(d2, c2) ||
            vfind(d1, c2) && vfind(d2, c1))
            continue;
        if (c1 == '6') c1 = '9';
        else if (c1 == '9') c1 = '6';
        else if (c2 == '6') c2 = '9';
        else if (c2 == '9') c2 = '6';
        else return false;
        if (vfind(d1, c1) && vfind(d2, c2) ||
            vfind(d1, c2) && vfind(d2, c1))
            continue;
        return false;
    }
    return true;
}

int main()
{
    vector<vector<char> > all;
    vector<char> cur;
    find_combinations(all, cur, 0);
    int res = 0;
    for (int i = 0; i < all.size(); i++)
        for (int j = i; j < all.size(); j++)
            res += is_legal(all[i], all[j]);
    cout << res << endl;
}
