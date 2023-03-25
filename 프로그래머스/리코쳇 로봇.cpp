#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int sx, sy, ex, ey;
int d[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
pair<int, int> getNextCoord(int x, int y, int dir, vector<string> board) {
    while (1) {
        x += dx[dir];
        y += dy[dir];
        if (x < 0 || x >= n || y < 0 || y >= m)
            break;
        if (board[x][y] == 'D')
            break;
    }
    return { x - dx[dir], y - dy[dir] };
}
int bfs(vector<string> board) {
    d[sx][sy] = 0;
    queue<pair<int, int>> q;
    q.push({ sx, sy });
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == ex && y == ey) return d[x][y];
        for (int i = 0; i < 4; i++) {
            pair<int, int> xy = getNextCoord(x, y, i, board);
            int nx = xy.first;
            int ny = xy.second;
            if (d[nx][ny] == -1) {
                d[nx][ny] = d[x][y] + 1;
                q.push({ nx,ny });
            }
        }
    }
    return -1;
}
int solution(vector<string> board) {
    int answer = 0;
    n = board.size();
    m = board[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R') {
                sx = i;
                sy = j;
            }
            else if (board[i][j] == 'G') {
                ex = i;
                ey = j;
            }
        }
    }

    memset(d, -1, sizeof(d));
    answer = bfs(board);

    return answer;
}