#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int d[5][5];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool bfs(vector<string> places, int x, int y) {
    cout << "x : " << x << ", y : " << y << '\n';
    d[x][y] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if (d[x][y] == 2) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
                if (d[nx][ny] == -1 && places[nx][ny] != 'X') {
                    if (places[nx][ny] == 'P') return 0;
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    return 1;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int i = 0; i < places.size(); i++) {
        int ok = 1;
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (places[i][j][k] == 'P') {
                    memset(d, -1, sizeof(d));
                    if (!bfs(places[i], j, k)) {
                        ok = 0;
                        break;
                    }
                }
            }
            if (!ok) break;
        }
        answer.push_back(ok);
    }


    return answer;
}