#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> pSum(n + 1, vector<int>(m + 1));
    for (int i = 0; i < skill.size(); i++) {
        int type = skill[i][0];
        int x1 = skill[i][1];
        int y1 = skill[i][2];
        int x2 = skill[i][3];
        int y2 = skill[i][4];
        int amount = skill[i][5];
        if (type == 1)
            amount *= -1;

        pSum[x2 + 1][y2 + 1] += amount;
        pSum[x2 + 1][y1] -= amount;
        pSum[x1][y2 + 1] -= amount;
        pSum[x1][y1] += amount;
    }

    
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0)
                pSum[i][j] += pSum[i - 1][j];
            if (j > 0)
                pSum[i][j] += pSum[i][j - 1];
            if (i > 0 && j > 0)
                pSum[i][j] -= pSum[i - 1][j - 1];
            
            if (board[i][j] + pSum[i][j] > 0)
                answer++;
        }
    }
    
    return answer;
}