#include <string>
#include <vector>
#include <queue>
using namespace std;
bool check[201];
void bfs(int x, int n, vector<vector<int>> computers) {
    check[x] = true;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        x = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (x != i && !check[i] && computers[x][i] == 1) {
                check[i] = true;
                q.push(i);
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (!check[i]) {
            bfs(i, n, computers);
            answer++;
        }
    }

    return answer;
}