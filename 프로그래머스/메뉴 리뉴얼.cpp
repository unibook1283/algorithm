#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> m[11];
int max_order[11];
void go(string s, int index, string order) {
    if (index == order.length()) {
        if (s.length() >= 2) {
            m[s.length()][s]++;
            max_order[s.length()] = max(max_order[s.length()], m[s.length()][s]);
        }
        return;
    }
    go(s, index + 1, order);
    go(s + order[index], index + 1, order);
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
    }
    for (int i = 0; i < orders.size(); i++) {
        go("", 0, orders[i]);
    }
    
    for (int i = 0; i < course.size(); i++) {
        for (auto iter = m[course[i]].begin(); iter != m[course[i]].end(); iter++) {
            if (iter->second >= 2 && iter->second == max_order[course[i]]) answer.push_back(iter->first);
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}