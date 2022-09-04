#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    
    map<string, int> id_index;
    map<string, set<string>> m; // 신고받은 사람, set(신고자)
    for (int i = 0; i < id_list.size(); i++) {
        string id = id_list[i];
        id_index[id] = i;
    }

    for (int i = 0; i < report.size(); i++) {
        string s = report[i];
        string sender = s.substr(0, s.find(' '));
        string receiver = s.substr(s.find(' '), s.length() - s.find(' '));
        m[receiver].insert(sender);
    }

    for (auto p : m) {
        cout << p.first << ' ' << p.second.size() << '\n';
        if (p.second.size() >= k) {
            for (auto q : p.second) {
                int index = id_index[q];
                answer[index]++;
            }
        }
    }

    return answer;
}