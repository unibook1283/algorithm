#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool cmp(vector<string> u, vector<string> v) {
    return u[1] < v[1];
}
string convertTime(string time) {
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3));
    int intTime = 60 * hour + minute;
    return to_string(intTime);
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;

    for (int i = 0; i < plans.size(); i++) {
        plans[i][1] = convertTime(plans[i][1]);
    }

    sort(plans.begin(), plans.end(), cmp);

    stack<pair<string, int>> s; // (name, 남은 playtime)
    int prevTaskEndTime;
    int leftTime;
    for (int i = 1; i < plans.size(); i++) {
        prevTaskEndTime = stoi(plans[i - 1][1]) + stoi(plans[i - 1][2]);
        leftTime = stoi(plans[i][1]) - prevTaskEndTime;
        if (leftTime >= 0) {
            // 이번 과제를 시작하기 전에 이전 과제가 끝난 경우
            // stack에 있는 미완료 과제들을 진행.
            answer.push_back(plans[i - 1][0]);
            while (!s.empty() && leftTime > 0) {
                if (s.top().second <= leftTime) {
                    answer.push_back(s.top().first);
                    leftTime -= s.top().second;
                    s.pop();
                }
                else {
                    s.top().second -= leftTime;
                    break;
                }
            }
        }
        else if (leftTime < 0) {
            s.push({ plans[i - 1][0], -leftTime });
        }
    }
    answer.push_back(plans.back()[0]);
    while (!s.empty()) {
        answer.push_back(s.top().first);
        s.pop();
    }

    return answer;
}
int main() {
    solution({ {"science", "12:40", "50"} ,{"music", "12:20", "40"},{"history", "14:00", "30"},{"computer", "12:30", "100"} });
    return 0;
}