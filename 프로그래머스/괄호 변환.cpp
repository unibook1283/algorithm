#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

pair<string, string> separate(string w) {
    int open = 0, close = 0;
    for (int i = 0; i < w.size(); i++) {
        if (w[i] == '(') open++;
        else close++;
        if (open == close) {
            string left = w.substr(0, open + close);
            string right = w.substr(open + close);
            return make_pair(left, right);
        }
    }

}
bool is_right_string(string s) {
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            cnt++;
        }
        else {
            if (cnt == 0) return false;
            cnt--;
        }
    }
    return cnt == 0;
}
string solution(string p) {
    if (p.empty()) return "";
    pair<string, string> uv = separate(p);
    string u = uv.first;
    string v = uv.second;
    if (is_right_string(u)) {
        return u + solution(v);
    }

    string res = "(";
    res += solution(v);
    res += ")";
    for (int i = 1; i < u.length() - 1; i++) {
        if (u[i] == '(') res += ')';
        else res += '(';
    }

    return res;
}