#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
string to_lower(string s) {
    string ret;
    for (int i = 0; i < s.length(); i++) {
        ret += tolower(s[i]);
    }
    return ret;
}
void slice(string s, map<string, int>& m) {
    for (int i = 0; i < s.length() - 1; i++) {
        if ((('a' <= s[i] && s[i] <= 'z')
            || ('A' <= s[i] && s[i] <= 'Z'))
            && (('a' <= s[i + 1] && s[i + 1] <= 'z')
                || ('A' <= s[i + 1] && s[i + 1] <= 'Z')))
        m[s.substr(i, 2)]++;
    }
}
int solution(string str1, string str2) {
    int answer = 0;

    str1 = to_lower(str1);
    str2 = to_lower(str2);

    map<string, int> m1, m2;
    slice(str1, m1);
    slice(str2, m2);

    int i_size = 0; // 교집합
    int u_size = 0; // 합집합
    for (auto iter = m1.begin(); iter != m1.end(); iter++) {
        string s = iter->first;
        int cnt1 = iter->second;
        int cnt2 = m2[s];
        i_size += min(cnt1, cnt2);
        u_size += max(cnt1, cnt2);
        m2.erase(s);
    }
    for (auto iter = m2.begin(); iter != m2.end(); iter++) {
        u_size += iter->second;
    }
    if (u_size == 0) answer = 65536;
    else answer = 65536 * i_size / u_size;
    
    return answer;
}