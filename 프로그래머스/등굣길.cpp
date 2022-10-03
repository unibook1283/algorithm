#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool p[101][101];
long long d[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for (int i = 0; i < puddles.size(); i++) {
        int x = puddles[i][0];
        int y = puddles[i][1];
        p[y- 1][x - 1] = true;
    }
    d[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) continue;
            if (!p[i][j]) {
                if (i == 0) d[i][j] = d[i][j - 1];
                else if (j == 0) d[i][j] = d[i - 1][j];
                else d[i][j] = (d[i - 1][j] + d[i][j - 1]) % 1000000007;
            }
        }
    }
    return d[n - 1][m - 1];
}