#include <iostream>
#include <cmath>

using namespace std;

#define N 2000000

int main()
{
    int closest_ans = N;
    int closest_area = -1;

    // Define solutions for single row rectangles
    const int BUF = sqrt(N)*2;
    int* len = new int[BUF];
    len[0] = 0;
    for (int i = 1; i < BUF; i++)
        len[i] = len[i-1] + i;

    // Find # of solutions for rectangles of height h and length l
    // until l > h
    for (int h = 1, done = 0; !done; h++) {
        for (int l = 1, cur = 0; !done; l++) {
            cur += len[h]*l;
            int diff = abs(N - cur);
            if (diff < closest_ans) {
                closest_ans = diff;
                closest_area = h*l;
            }
            if (cur > N) {
                done = l <= h;
                break;
            }
        }
    }
    cout << closest_area << endl;

    delete len;
}
