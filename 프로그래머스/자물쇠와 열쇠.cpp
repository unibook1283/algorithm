#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;
bool full(vector<vector<int>> lock) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (lock[i][j] == 0) return false;
        }
    }
    return true;
}
bool fit(vector<vector<int>> key, vector<vector<int>>& lock, int x, int y) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (x + i >= m - 1 && x + i < m + n - 1 && y + j >= m - 1 && y + j < m + n - 1) {
                if (key[i][j] ^ lock[x + i - (m - 1)][y + j - (m - 1)])
                    lock[x + i - (m - 1)][y + j - (m - 1)] |= key[i][j];
                else // 자물쇠의 돌기와 열쇠의 돌기가 만나는 경우
                    return false;
            }
        }
    }
    return true;
}
void rotate_key(vector<vector<int>>& key) {
    vector<vector<int>> temp = key;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            temp[j][m - i - 1] = key[i][j];
        }
    }
    key = temp;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    n = lock.size();
    m = key.size();
    if (full(lock))
        return true;

    for (int degree = 0; degree < 4; degree++) {
        for (int i = 0; i < m + n - 1; i++) {
            for (int j = 0; j < m + n - 1; j++) {
                vector<vector<int>> temp = lock;
                if (!fit(key, temp, i, j))
                    continue;
                if (full(temp))
                    return true;
            }
        }

        if (degree == 3) break;
        rotate_key(key);
    }
    
    return false;
}