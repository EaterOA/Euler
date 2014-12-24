#include <iostream>
#include <stack>

using namespace std;

#define N 10000000

inline int get_sum(int n)
{
    int sum = 0;
    while (n) {
        int r = n % 10;
        sum += r*r;
        n /= 10;
    }
    return sum;
}

int main()
{
    // hyperoptimzied version of the brute force solution
    // optimization 1: all sums are <= 7*81, so precompute cycles of n < 1000
    // optimization 2: cache the rightmost digit to avoid expensive sum
    // computation 90% of the time
    int sol = 0;
    int seen[1000] = {0};
    seen[1] = 1;
    seen[89] = 89;
    stack<int> s;
    for (int i = 1; i < 1000; i++) {
        int cur = get_sum(i);
        while (!seen[cur]) {
            s.push(cur);
            cur = get_sum(cur);
        }
        sol += seen[cur] == 89;
        seen[i] = seen[cur];
        while (!s.empty()) {
            seen[s.top()] = seen[cur];
            s.pop();
        }
    }
    int rightmost = 0;
    int sum = 1;
    for (int i = 1001; i < N; i++) {
        if (rightmost == 9) {
            sum = get_sum(i/10);
            rightmost = 0;
        }
        else {
            sum += 2*rightmost+1;
            rightmost++;
        }
        sol += seen[sum] == 89;
    }
    cout << sol << endl;
}
