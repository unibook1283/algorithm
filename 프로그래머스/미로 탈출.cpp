#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int d[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int bfs(int sx, int sy, int ex, int ey, vector<string> maps) {
    d[sx][sy] = 0;
    queue<pair<int, int>> q;
    q.push({ sx, sy });
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        cout << x << ' ' << y << '\n';
        if (x == ex && y == ey) {
            cout << d[x][y] << '\n';
            return d[x][y];
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (maps[nx][ny] != 'X' && d[nx][ny] == -1) {
                    d[nx][ny] = d[x][y] + 1;
                    q.push({ nx,ny });
                }
            }
        }
    }
    return -1;
}
int solution(vector<string> maps) {
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    int sx, sy, ex, ey, lx, ly;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maps[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            else if (maps[i][j] == 'E') {
                ex = i;
                ey = j;
            }
            else if (maps[i][j] == 'L') {
                lx = i;
                ly = j;
            }
        }
    }
    memset(d, -1, sizeof(d));
    int stol = bfs(sx, sy, lx, ly, maps);
    if (stol == -1) return -1;

    memset(d, -1, sizeof(d));
    int ltoe = bfs(lx, ly, ex, ey, maps);
    if (ltoe == -1) return -1;

    answer = stol + ltoe;

    return answer;
}