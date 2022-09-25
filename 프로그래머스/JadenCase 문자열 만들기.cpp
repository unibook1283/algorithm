#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<string> v;
    int prev = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            v.push_back(s.substr(prev, i - prev));
            prev = i + 1;
        }
    }
    v.push_back(s.substr(prev));
    for (int i = 0; i < v.size(); i++) {
        if ('a' <= v[i][0] && v[i][0] <= 'z') {
            v[i][0] += 'A' - 'a';
        }
        for (int j = 1; j < v[i].length(); j++) {
            if ('A' <= v[i][j] && v[i][j] <= 'Z') {
                v[i][j] += 'a' - 'A';
            }
        }
        answer += v[i] + ' ';
    }
    answer.pop_back();

    return answer;
}