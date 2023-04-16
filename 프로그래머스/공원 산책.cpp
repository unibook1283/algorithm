#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, pair<int, int>> dir;  // op, (dx, dy)
int x = -1, y;
int n, m;
void go(vector<string> park, int dx, int dy, int dist) {
    int nx = x;
    int ny = y;
    while (dist--) {
        nx += dx;
        ny += dy;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            return;
        if (park[nx][ny] == 'X')
            return;
    }
    x = nx;
    y = ny;
}
vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    dir['N'] = { -1,0 };
    dir['S'] = { 1,0 };
    dir['W'] = { 0,-1 };
    dir['E'] = { 0,1 };
    n = park.size();
    m = park[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (park[i][j] == 'S') {
                x = i;
                y = j;
                break;
            }
        }
        if (x != -1) break;
    }

    for (string route : routes) {
        int dx = dir[route[0]].first;
        int dy = dir[route[0]].second;
        int dist = stoi(route.substr(2));
        go(park, dx, dy, dist);
    }

    answer.push_back(x);
    answer.push_back(y);

    return answer;
}