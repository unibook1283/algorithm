#include <iostream>
#include <string>
#include <vector>

using namespace std;

string answer = "impossible";
int dx[] = { 1,0,0,-1 };
int dy[] = { 0,-1,1,0 };
string cmd = "dlru";
bool canReach(int x, int y, int ex, int ey, int limit) {
    int dist = abs(x - ex) + abs(y - ey);
    return dist <= limit && dist % 2 == limit % 2;
}
void dfs(int n, int m, int x, int y, int ex, int ey, int k, string s) {
    if (answer != "impossible") return;
    if (!canReach(x, y, ex, ey, k - s.length())) {
        return;
    }
    if (s.length() == k) {
        if (x == ex && y == ey) {
            answer = s;
            return;
        }
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            dfs(n, m, nx, ny, ex, ey, k, s + cmd[i]);
        }
    }
}
string solution(int n, int m, int x, int y, int r, int c, int k) {
    dfs(n, m, x - 1, y - 1, r - 1, c - 1, k, "");

    return answer;
}