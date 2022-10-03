#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dx[] = { 0,0,1,1 };
int dy[] = { 0,1,0,1 };
vector<pair<int, int>> get_erase_blocks(int m, int n, vector<string> board) {
    vector<pair<int, int>> ret;
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            char ch = board[i][j];
            if (ch == '0') continue;
            bool ok = true;
            for (int k = 1; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (board[nx][ny] != ch) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    ret.push_back(make_pair(nx, ny));
                }
            }
        }
    }
    return ret;
}
void erase(vector<string>& board, vector<pair<int, int>> erase_blocks) {
    for (int i = 0; i < erase_blocks.size(); i++) {
        int x = erase_blocks[i].first;
        int y = erase_blocks[i].second;
        board[x][y] = '0';
    }
}
void gravity(int m, int n, vector<string>& board) {
    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            if (board[j][i] == '0') {
                int x = j;
                while (x > 0 && board[x][i] == '0') {
                    x--;
                }
                board[j][i] = board[x][i];
                board[x][i] = '0';
            }
        }
    }
}
int solution(int m, int n, vector<string> board) {
    int answer = 0;

    while (1) {
        vector<pair<int, int>> e;
        e = get_erase_blocks(m, n, board);
        sort(e.begin(), e.end());
        e.erase(unique(e.begin(), e.end()), e.end());
        int e_size = e.size();
        if (e_size == 0) break;
        answer += e_size;
        erase(board, e);
        gravity(m, n, board);
    }

    return answer;
}