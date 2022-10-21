#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool a[101][101];
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for (int i = 0; i < results.size(); i++) {
        a[results[i][0]][results[i][1]] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                a[j][k] = a[j][k] | (a[j][i] & a[i][k]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            cnt += a[i][j] | a[j][i];
        }
        if (cnt == n - 1) answer++;
    }

    return answer;
}