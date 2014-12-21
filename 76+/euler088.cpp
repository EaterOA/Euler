#include <iostream>
#include <algorithm>
#include <cstring>

#define N 12000

using namespace std;

void chain(int prod, int sum, int size, int left, int smallest[])
{
    int index = prod - sum + size;
    if (size > 1 && prod < smallest[index])
        smallest[index] = prod;
    for (int i = left; N > i && N >= prod*i - (sum+i) + size+1; i++)
        chain(prod*i, sum+i, size+1, i, smallest);
}

int main()
{
    int smallest[N+1];
    memset(smallest, 0x7f, (N+1)*sizeof(int));
    chain(1, 0, 0, 2, smallest);
    sort(smallest+2, smallest+N+1);
    int sum = 0;
    for (int i = 2; i <= N; i++) {
        sum += smallest[i];
        while (i <= N && smallest[i] == smallest[i+1])
            i++;
    }
    cout << sum << endl;
}
