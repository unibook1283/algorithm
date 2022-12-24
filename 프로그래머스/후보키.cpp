#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int filter(vector<int> super_key, int col) {
    int n = super_key.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        bool minimum = true;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if ((super_key[i] & super_key[j]) == super_key[j]) {
                minimum = false;
                break;
            }
            if (!minimum) break;
        }
        if (minimum) cnt++;
    }
    return cnt;
}
int solution(vector<vector<string>> relation) {
    int answer = 0;
    int row = relation.size();
    int col = relation[0].size();
    
    vector<int> super_key;
    for (int i = 1; i < (1 << col); i++) {
        set<vector<string>> s;
        for (int j = 0; j < row; j++) {
            vector<string> v;
            for (int k = 0; k < col; k++) {
                if (i & (1 << k)) {
                    v.push_back(relation[j][k]);
                }
            }
            s.insert(v);
        }
        if (s.size() == row)
            super_key.push_back(i);
    }
    answer = filter(super_key, col);


    return answer;
}