#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int L = 100;
int bestSet[4];
int bestValue;

double eval(double n1, double n2, int op)
{
    if (op == 0) return n1 + n2;
    if (op == 1) return n1 - n2;
    if (op == 2) return n1 * n2;
    return n1 / n2;
}

bool valid(double d)
{
    if (d < 1.0)
        return false;
    if (d > L)
        return false;
    if (d != d)
        return false;
    if ((int)d != d)
        return false;
    return true;
}

// find all 64 combinations of 3 operators
void findOperations(int num[], int op[], int len, bool seen[])
{
    if (len == 3) {
        // all 5 ways of applying operations (parentheses)
        double p1 = eval(eval(eval(num[0], num[1], op[0]), num[2], op[1]), num[3], op[2]);
        double p2 = eval(eval(num[0], num[1], op[0]), eval(num[2], num[3], op[2]), op[1]);
        double p3 = eval(eval(num[0], eval(num[1], num[2], op[1]), op[0]), num[3], op[2]);
        double p4 = eval(num[0], eval(eval(num[1], num[2], op[1]), num[3], op[2]), op[0]);
        double p5 = eval(num[0], eval(num[1], eval(num[2], num[3], op[2]), op[1]), op[0]);
        if (valid(p1)) seen[(int)p1] = true;
        if (valid(p2)) seen[(int)p2] = true;
        if (valid(p3)) seen[(int)p3] = true;
        if (valid(p4)) seen[(int)p4] = true;
        if (valid(p5)) seen[(int)p5] = true;
        return;
    }
    for (int i = 0; i < 4; i++) {
        op[len] = i;
        findOperations(num, op, len+1, seen);
    }
}

// find all 126 combinations of 9 digits
void findSet(int num[], int len, int d)
{
    if (len == 4) {
        // find all 24 ways of permutating 4 digits
        bool seen[L] = {0};
        int op[3];
        do {
            findOperations(num, op, 0, seen);
        } while (next_permutation(num, num+len));
        int i = 0;
        while (seen[i+1]) i++;
        if (i > bestValue) {
            memcpy(bestSet, num, sizeof(int) * len);
            bestValue = i;
        }
        return;
    }
    for (int i = d; i <= 9; i++) {
        num[len] = i;
        findSet(num, len+1, i+1);
    }
}

int main()
{
    int num[4];
    findSet(num, 0, 1);
    for (int i = 0; i < 4; i++)
        cout << bestSet[i];
    cout << endl;
}
