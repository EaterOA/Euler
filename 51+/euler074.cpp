#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define MAXN 1000000
const int fac[] = {1,1,2,6,24,120,720,5040,40320,362880};

int getFac(int n)
{
    int sum = 0;
    while (n > 0) {
        sum += fac[n % 10];
        n /= 10;
    }
    return sum;
}

int main()
{
    char start[MAXN] = {0};
    start[169] = 3; start[363601] = 3; start[1454] = 3;
    start[871] = 2; start[45361] = 2;
    start[872] = 2; start[45362] = 2;
    start[0] = 1;
    start[1] = 1;
    start[2] = 1;
    start[145] = 1;
    start[40585] = 1;
    int list[60];
    int res = 0, size;
    for (int i = 0, cur, j; i < MAXN; i++) {
        size = 0;
        for (cur = i; cur >= MAXN || !start[cur]; cur = getFac(cur))
            list[size++] = cur;
        for (j = 0; j < size; j++)
            if (list[j] < MAXN)
                start[list[j]] = (size - j) + start[cur];
        res += (start[i] == 60);
    }
    cout << res << endl;
}
