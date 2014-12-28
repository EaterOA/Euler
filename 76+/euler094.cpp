#include <iostream>
#include <math.h>

using namespace std;

#define N 333333333

inline bool isInt(double d)
{
    return (long long)d == d;
}

int main()
{
    // Bit of a cheat solution.
    // I bruteforced on the first million or so and found an interesting
    // pattern in the solutions that came up, namely that each i is a little
    // less than 4 times the previous. Also, the solution alternates between
    // the +1 triangle and the -1 triangle. So I simply wrote a loop that
    // exploits those patterns.
    // The full mathematical reasoning behind this pattern as well as much more
    // elegant solutions, as always, can be found in the main website's
    // discussion thread.
    long long sum = 0;
    int pos = 1;
    for (long long i = 5; i <= N; i++) {
        double sq = sqrt(4.0*i*i - (i+pos)*(i+pos));
        if (isInt(sq)) {
            sum += 2*i + (i+pos);
            i = (long long)(0.9*4*i) - 3;
            pos = -pos;
        }
    }
    cout << sum << endl;
}
