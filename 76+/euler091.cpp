#include <iostream>

using namespace std;

#define N 50

int gcd(int a, int b)
{
    int c;
    while (b) {
        c = b;
        b = a % b;
        a = c;
    }
    return a;
}

int main()
{
    int res = N*N;
    for (int x = 0; x <= N; x++)
        for (int y = 0; y <= N; y++) {
            if (x == 0 && y == 0)
                continue;
            int g = gcd(x, y);
            int gx = x/g;
            int gy = y/g;
            for (int cx = x+gy, cy = y-gx; cx >= 0 && cx <= N && cy >= 0 && cy <= N; cx+=gy, cy-=gx)
                res++;
            for (int cx = x-gy, cy = y+gx; cx >= 0 && cx <= N && cy >= 0 && cy <= N; cx-=gy, cy+=gx)
                res++;
        }
    cout << res << endl;
}
