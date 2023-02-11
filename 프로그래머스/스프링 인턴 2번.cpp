#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int n, m;
bool check[1010][1010];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int bfs(int x, int y, vector<string> new_grid) {
    check[x][y] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    int cnt = 0;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        cnt++;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n + 2 && ny >= 0 && ny < m + 2) {
                if (!check[nx][ny] && new_grid[nx][ny] == '.') {
                    check[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    return cnt;
}
vector<string> make_new_grid(vector<string> grid) {
    vector<string> new_grid;
    string s;
    for (int i = 0; i < m + 2; i++)
        s += '.';
    new_grid.push_back(s);
    for (int i = 0; i < n; i++) {
        string str = grid[i];
        string new_str = '.' + str + '.';
        new_grid.push_back(new_str);
    }
    new_grid.push_back(s);
    return new_grid;
}
int solution(vector<string> grid) {
    int answer = 0;
    n = grid.size();
    m = grid[0].size();
    vector<string> new_grid = make_new_grid(grid);

    int outside = bfs(0, 0, new_grid);
    answer = (n + 2) * (m + 2) - outside;

    return answer;
}