#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
vector<int> v[101];
bool check[101];
int bfs(int a, int b) { // a에서 bfs를 돌림. b로는 못 가게. a쪽 노드의 개수를 return.
    int cnt = 0;
    check[a] = true;
    queue<int> q;
    q.push(a);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < v[x].size(); i++) {
            int nx = v[x][i];
            if (!check[nx] && nx != b) {
                check[nx] = true;
                q.push(nx);
            }
        }
    }
    return cnt;
}
int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    for (int i = 0; i < wires.size(); i++) {
        int from = wires[i][0];
        int to = wires[i][1];
        v[from].push_back(to);
        v[to].push_back(from);
    }

    for (int i = 0; i < wires.size(); i++) {
        memset(check, false, sizeof(check));
        int a = wires[i][0];
        int b = wires[i][1];
        int res = bfs(a, b);
        cout << res << ' ' << n - res << '\n';
        answer = min(answer, abs(res - (n - res)));
    }

    return answer;
}