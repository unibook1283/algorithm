#include <iostream>
#include <string>
#include <vector>

using namespace std;

void parseInfo(vector<string> info, vector<vector<string>>& applicants) {
    for (int i = 0; i < info.size(); i++) {
        vector<string> v;
        int start = 0, index;
        while (1) {
            index = info[i].find(' ', start);
            if (index == -1) break;
            string s = info[i].substr(start, index - start);
            v.push_back(s);
            start = index + 1;
        }
        v.push_back(info[i].substr(start));
        applicants.push_back(v);
    }
}
vector<string> parseQuery(string q) {
    vector<string> v;
    int start = 0, index;
    while (1) {
        index = q.find(" and ", start);
        if (index == -1) break;
        string s = q.substr(start, index - start);
        v.push_back(s);
        start = index + 5;
    }
    string soulFoodAndScore = q.substr(start);
    index = soulFoodAndScore.find(' ');
    v.push_back(soulFoodAndScore.substr(0, index));
    v.push_back(soulFoodAndScore.substr(index + 1));
    return v;
}
int getCount(vector<vector<string>> applicants, vector<string> condition) {
    int cnt = 0;
    for (int i = 0; i < applicants.size(); i++) {
        vector<string> applicant = applicants[i];
        bool match = true;
        for (int j = 0; j < 4; j++) {
            if (condition[j] != "-" && applicant[j] != condition[j]) {
                match = false;
                break;
            }
        }
        if (stoi(applicant[4]) < stoi(condition[4])) {
            match = false;
        }
        if (match) cnt++;
    }
    return cnt;
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<vector<string>> applicants;
    parseInfo(info, applicants);
    
    for (int i = 0; i < query.size(); i++) {
        vector<string> condition = parseQuery(query[i]);
        int count = getCount(applicants, condition);
        answer.push_back(count);
    }

    return answer;
}