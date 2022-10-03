#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int d[100001][4];
int solution(vector<vector<int> > land)
{
    int answer = 0;
    int n = land.size();
    for (int i = 0; i < 4; i++) {
        d[0][i] = land[0][i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (j == k) continue;
                d[i][j] = max(d[i][j], d[i - 1][k] + land[i][j]);
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        answer = max(answer, d[n - 1][i]);
    }
    return answer;
}