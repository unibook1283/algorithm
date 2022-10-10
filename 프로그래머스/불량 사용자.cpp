#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool check[9];
set<vector<string>> s;
bool is_ok(string user_id, string banned_id) {
    if (user_id.length() != banned_id.length()) return false;
    for (int i = 0; i < user_id.length(); i++) {
        if (user_id[i] == banned_id[i] || banned_id[i] == '*') continue;
        else return false;
    }
    return true;
}
void go(vector<string> user_id, vector<string> banned_id, int index, vector<string> restrictions) {
    if (index == banned_id.size()) {
        sort(restrictions.begin(), restrictions.end());
        s.insert(restrictions);
        return;
    }
    for (int i = 0; i < user_id.size(); i++) {
        if (!check[i]) {
            if (is_ok(user_id[i], banned_id[index])) {
                check[i] = true;
                restrictions.push_back(user_id[i]);
                go(user_id, banned_id, index + 1, restrictions);
                restrictions.pop_back();
                check[i] = false;
            }
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    go(user_id, banned_id, 0, {});
    return s.size();
}