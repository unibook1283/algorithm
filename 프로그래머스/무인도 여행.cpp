#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
bool check[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int bfs(int x, int y, vector<string> maps) {
    check[x][y] = true;
    queue<pair<int, int>> q;
    q.push({ x,y });
    int ret = 0;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        ret += maps[x][y] - '0';
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (maps[nx][ny] != 'X' && !check[nx][ny]) {
                    check[nx][ny] = true;
                    q.push({ nx,ny });
                }
            }
        }
    }
    return ret;
}
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    n = maps.size();
    m = maps[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maps[i][j] != 'X' && !check[i][j]) {
                int cnt = bfs(i, j, maps);
                answer.push_back(cnt);
            }
        }
    }
    if (answer.empty())
        answer.push_back(-1);
    else 
        sort(answer.begin(), answer.end());

    return answer;
}