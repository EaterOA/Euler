#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

#define N 1000000
#define SQ 5000

int main()
{
    // Find all squares up to SQ
    set<int> squares;
    for (int i = 1; i < SQ; i++)
        squares.insert(i*i);

    // Each M level includes at least the previous M's solutions
    // Then any potential solutions must have at least one side that is M
    // The shortest path for the cuboid is always the square root of the
    // sum of the two smaller numbers squared plus the larger number squared.
    // If x <= y <= z, then shortest path = sqrt((x+y)^2 + z^2)
    // Since M necessarily must be the largest number, at each level our task
    // is to find two numbers whose sum squared adds with M^2 to create another
    // square.
    //
    // Since I have a set of all squares, I can simply look for all squares
    // whose difference with M^2 is also a square. These squares range from
    // upper_bound(M) up to (2*M)^2 + M^2. If found, all pairs of numbers
    // 1 <= x,y <= M that sum up to the square root of that square will be part
    // of the solution.
    //
    int M, prev = 0;
    for (M = 2;; M++) {
        // Include previous level's solutions
        int count = prev;
        int MM = M*M;
        int limit = 4*MM + MM;
        set<int>::iterator lb = upper_bound(squares.begin(), squares.end(), MM);
        // Find all shortest paths squared
        while (*lb <= limit) {
            int diff = *lb - MM;
            // The difference is also a square
            if (squares.find(diff) != squares.end()) {
                int sum = sqrt(diff);
                // Count all legal pairs of numbers that sum to that difference
                for (int i = 1; i <= sum/2; i++)
                    count += sum-i <= M;
            }
            lb++;
        }
        prev = count;
        if (count > N)
            break;
    }
    cout << M << endl;
}
