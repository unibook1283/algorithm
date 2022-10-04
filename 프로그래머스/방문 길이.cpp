#include <iostream>
#include <string>
#include <map>

using namespace std;
bool check[11][11][4];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int r_dir[4] = { 1,0,3,2 };
int solution(string dirs) {
    int answer = 0;

    map<char, int> m;
    m['U'] = 0;
    m['D'] = 1;
    m['R'] = 2;
    m['L'] = 3;

    int x = 5, y = 5;
    for (int i = 0; i < dirs.length(); i++) {
        char op = dirs[i];
        int dir = m[op];
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx > 10 || ny < 0 || ny > 10) {
            continue;
        }
        if (!check[nx][ny][dir] && !check[x][y][r_dir[dir]]) {
            check[nx][ny][dir] = true;
            answer++;
        }
        x = nx;
        y = ny;
    }
    return answer;
}
int main() {
    cout << solution("LLURRDLL");
    return 0;
}