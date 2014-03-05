#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>

#ifdef _WIN64
    #define sscanf sscanf_s
#elif _WIN32
    #define sscanf sscanf_s
#endif

using namespace std;

struct Point
{
    int n, r, c;
    Point(int nn, int rr, int cc): n(nn), r(rr), c(cc) {}
    bool operator<(const Point& other) const { return n > other.n; }
};

int main()
{
    const int N = 80;
    const int BUF = 1000;
    ifstream fin("matrix.txt");
    //More old school parsing because streams are sloooooooow
    int num[N][N] = {0};
    for (int i = 0; i < N; i++) {
        char s[BUF] = {0};
        char* c = s, *n = s;
        fin >> s;
        for (int j = 0; j < N && n; j++) {
            n = strchr(c, ',');
            if (n) *n = 0;
            sscanf(c, "%d", &num[i][j]);
            c = n+1;
        }
    }
    //Canonical dijkstra
    int sum[N][N];
    memset(sum, 0x7f, N*N*4);
    priority_queue<Point> pq;
    for (int i = 0; i < N; i++) {
        sum[i][0] = num[i][0];
        pq.push(Point(sum[i][0], i, 0));
    }
    while (!pq.empty()) {
        Point p = pq.top(); pq.pop();
        if (p.c+1 == N) {
            cout << p.n << endl;
            break;
        }
        if (p.r > 0 && p.n + num[p.r-1][p.c] < sum[p.r-1][p.c]) {
            sum[p.r-1][p.c] = p.n + num[p.r-1][p.c];
            pq.push(Point(sum[p.r-1][p.c], p.r-1, p.c));
        }
        if (p.r+1 < N && p.n + num[p.r+1][p.c] < sum[p.r+1][p.c]) {
            sum[p.r+1][p.c] = p.n + num[p.r+1][p.c];
            pq.push(Point(sum[p.r+1][p.c], p.r+1, p.c));
        }
        if (p.n + num[p.r][p.c+1] < sum[p.r][p.c+1]) {
            sum[p.r][p.c+1] = p.n + num[p.r][p.c+1];
            pq.push(Point(sum[p.r][p.c+1], p.r, p.c+1));
        }
    }
}