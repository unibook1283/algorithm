#include <iostream>
#include<vector>
using namespace std;

int d[1001][1001];
int solution(vector<vector<int>> board)
{
    int answer = board[0][0];

    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < n; i++) {
        d[i][0] = board[i][0];
    }
    for (int i = 0; i < m; i++) {
        d[0][i] = board[0][i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (board[i][j] == 1) {
                d[i][j] = min(d[i - 1][j], min(d[i][j - 1], d[i - 1][j - 1])) + 1;
                answer = max(answer, d[i][j]);
            }
        }
    }
    answer *= answer;

    return answer;
}