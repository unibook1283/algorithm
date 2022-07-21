#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<int> v[20001];
int d[20001];
int maxd = 0;
void bfs(int x) {
    memset(d, -1, sizeof(d));
    d[x] = 0;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        x = q.front();
        q.pop();
        for (int i = 0; i < v[x].size(); i++) {
            int nx = v[x][i];
            if (d[nx] == -1) {
                d[nx] = d[x] + 1;
                maxd = max(maxd, d[nx]);
                q.push(nx);
            }
        }
    }
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for (int i = 0; i < edge.size(); i++) {
        int a = edge[i][0];
        int b = edge[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(1);
    for (int i = 1; i <= n; i++) {
        if (d[i] == maxd) answer++;
    }

    return answer;
}