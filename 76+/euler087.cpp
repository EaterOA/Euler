#include <iostream>
#include <math.h>
#include <vector>
#include <cstring>
#include <set>

#define N 50000000

using namespace std;

vector<int> get_primes(int P)
{
    bool* sieve = new bool[P+1];
    memset(sieve, 0, P+1);
    int crossbound = (int)sqrt((double)P+1);
    for (int i = 2; i <= crossbound; i++)
        if (!sieve[i])
            for (int j = i*i; j <= P; j += i)
                sieve[j] = 1;
    vector<int> primes;
    for (int i = 2; i <= P; i++)
        if (!sieve[i])
            primes.push_back(i);
    delete sieve;
    return primes;
}

inline int get_pow(int v, int p)
{
    int res = 1;
    while (p --> 0)
        res *= v;
    return res;
}

int chain(int power, int sum, const vector<int> &primes, bool seen[])
{
    int res = 0;
    for (int i = 0; i < primes.size(); i++) {
        int p = get_pow(primes[i], power);
        if (p >= sum)
            break;
        if (power == 4) {
            if (!seen[sum-p]) {
                res++;
                seen[sum-p] = 1;
            }
        }
        else
            res += chain(power+1, sum-p, primes, seen);
    }
    return res;
}

int main()
{
    int max_prime = (int)sqrt(N);
    vector<int> primes = get_primes(max_prime);
    bool* seen = new bool[N];
    memset(seen, 0, N);
    cout << chain(2, N, primes, seen) << endl;
    delete seen;
}
