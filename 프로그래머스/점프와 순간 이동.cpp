#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int d[1000000001];
void bfs(int n) {
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x >= n) continue;
        if (x != 0) {
            if (2 * x <= n) {
                if (d[2 * x] > d[x]) {
                    q.push(2 * x);
                    d[2 * x] = d[x];
                }
            }
        }
        if (d[x + 1] > d[x]) {
            q.push(x + 1);
            d[x + 1] = min(d[x + 1], d[x] + 1);
        }
    }
}
int solution(int n)
{
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        d[i] = 987654321;
    }
    bfs(n);
    ans = d[n];
    return ans;
}