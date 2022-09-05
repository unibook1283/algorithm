#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    vector<pair<string, string>> commands;

    for (string s : record) {
        int start = 0;
        vector<string> v;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                v.push_back(s.substr(start, i - start));
                start = i + 1;
            }
        }
        if (v[0] == "Enter") {
            m[v[1]] = s.substr(start);
            commands.push_back(make_pair(v[0], v[1]));
        }
        else if (v[0] == "Leave") {
            commands.push_back(make_pair(v[0], s.substr(start)));
        }
        else if (v[0] == "Change") {
            m[v[1]] = s.substr(start);
        }

    }

    for (auto p : commands) {
        string el = p.first;
        string nickname = m[p.second];

        if (el == "Enter") {
            answer.push_back(nickname + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
        }
        else {
            answer.push_back(nickname + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
        }
    }

    return answer;
}