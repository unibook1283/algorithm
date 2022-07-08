#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    stack<int> s;
    int n = board[0].size();
    for (int i = 0; i < moves.size(); i++) {
        int y = moves[i] - 1;
        int x = 0;
        while (x < n && board[x][y] == 0) {
            x++;
        }
        if (x == n) continue;
        int picked = board[x][y];
        board[x][y] = 0;
        if (!s.empty()) {
            int top = s.top();
            if (top == picked) {
                s.pop();
                answer += 2;
                continue;
            }
        }
        s.push(picked);
    }

    return answer;
}
int main() {
    vector<vector<int>> board = {
        {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}}
    };
    vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };
    cout << solution(board, moves);
  
    return 0;
}