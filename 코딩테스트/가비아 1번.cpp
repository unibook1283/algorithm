#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map<string, int> m; // user별 최고 score 저장
bool isSamePq(priority_queue<pair<pair<int, int>, string>> q1, priority_queue<pair<pair<int, int>, string>> q2) {
    if (q1.size() != q2.size()) return false;
    while (!q1.empty()) {
        if (q1.top().second != q2.top().second) return false;
        q1.pop();
        q2.pop();
    }
    return true;
}
int solution(int K, vector<string> user_scores) {
    int answer = 0;

    priority_queue<pair<pair<int, int>, string>> pq, temp, prev;    // 점수, 몇 번 째 시도, 이름
    for (int i = 0; i < user_scores.size(); i++) {
        string s = user_scores[i];
        int index = s.find(' ');
        string name = s.substr(0, index);
        int score = stoi(s.substr(index + 1));
        if (score <= m[name]) continue;
        m[name] = max(m[name], score);

        prev = pq;

        temp.push({ {score, i}, name });

        while (!pq.empty() && -pq.top().first.first < score) {
            if (pq.top().second != name)
                temp.push({ { -pq.top().first.first, pq.top().first.second}, pq.top().second });
            pq.pop();
        }

        while (pq.size() < K && !temp.empty()) {
            pq.push({ { -temp.top().first.first, temp.top().first.second}, temp.top().second });
            temp.pop();
        }

        while (!temp.empty()) {
            temp.pop();
        }

        if (!isSamePq(pq, prev)) {
            answer++;
        }
    }

    return answer;
}