#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int n = wallpaper.size();
    int m = wallpaper[0].size();

    int sx = 51, sy = 51, ex = 0, ey = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (wallpaper[i][j] == '#') {
                sx = min(sx, i);
                sy = min(sy, j);
                ex = max(ex, i + 1);
                ey = max(ey, j + 1);
            }
        }
    }
    answer.push_back(sx);
    answer.push_back(sy);
    answer.push_back(ex);
    answer.push_back(ey);

    return answer;
}