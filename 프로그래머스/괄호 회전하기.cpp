#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
using namespace std;

string rotation(string s) {
    s += s[0];
    s.erase(0, 1);
    return s;
}
bool is_right(string s, map<char, char> m) {
    stack<char> stk;
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            stk.push(ch);
        }
        if (ch == ')' || ch == ']' || ch == '}') {
            if (stk.empty() || stk.top() != m[ch]) return false;
            stk.pop();
        }
    }
    return stk.empty();
}
int solution(string s) {
    int answer = 0;
    string init = s;

    map<char, char> m;
    m[')'] = '(';
    m[']'] = '[';
    m['}'] = '{';

    do {
        if (is_right(s, m)) {
            answer++;
        }
        s = rotation(s);
    } while (s != init);

    return answer;
}