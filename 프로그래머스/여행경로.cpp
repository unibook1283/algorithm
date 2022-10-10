#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check[10001];
vector<vector<string>> vec;
void go(int cnt, string from, vector<string> v, vector<vector<string>> tickets) {
    int n = tickets.size();
    if (cnt == n) {
        v.push_back(from);
        vec.push_back(v);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!check[i]) {
            if (tickets[i][0] == from) {
                check[i] = true;
                v.push_back(from);
                go(cnt + 1, tickets[i][1], v, tickets);
                v.pop_back();
                check[i] = false;
            }
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    go(0, "ICN", {}, tickets);
    sort(vec.begin(), vec.end());

    return vec[0];
}