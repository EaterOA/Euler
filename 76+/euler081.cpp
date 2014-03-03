#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#define MIN(a,b) (a < b ? a : b)
#define N 80

int main()
{
    ifstream fin("matrix.txt");
    int sum[N][N] = {0};
    for (int i = 0; i < N; i++) {
        string s;
        getline(fin, s);
        stringstream ss(s);
        for (int j = 0; j < N; j++) {
            getline(ss, s, ',');
            stringstream si(s);
            si >> sum[i][j];
            if (i > 0 && j > 0) sum[i][j] += MIN(sum[i-1][j], sum[i][j-1]);
            else if (i > 0) sum[i][j] += sum[i-1][j];
            else if (j > 0) sum[i][j] += sum[i][j-1];
        }
    }
    cout << sum[N-1][N-1] << endl;
}