#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
    int start = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            v.push_back(stoi(s.substr(start, i - start)));
            start = i;
        }
    }
    v.push_back(stoi(s.substr(start)));

    sort(v.begin(), v.end());
    to_string(v[0]);
    answer += to_string(v.front()) + ' ' + to_string(v.back());

    return answer;
}