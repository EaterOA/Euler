#include <iostream>

using namespace std;

#define MAXN 100

int main()
{
    int count[MAXN+1] = {0};
    count[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        for (int j = 0; j+i < MAXN+1; j++) {
            count[i+j] += count[j];
        }
    }
    cout << count[MAXN] << endl;
}
