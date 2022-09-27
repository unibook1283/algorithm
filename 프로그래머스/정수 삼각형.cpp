#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    vector<vector<int>> d(n, vector<int>(n, 0));
    d[0][0] = triangle[0][0];
    for (int i = 1; i < n; i++) {
        d[i][0] = d[i - 1][0] + triangle[i][0];
        d[i][i] = d[i - 1][i - 1] + triangle[i][i];
        for (int j = 1; j < i; j++) {
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + triangle[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        answer = max(answer, d[n - 1][i]);
    }
    return answer;
}