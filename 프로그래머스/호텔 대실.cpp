#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

int stringTimeToInt(string time) {
    stringstream ss(time);
    int hour, minute;
    char temp;
    ss >> hour >> temp >> minute;
    return hour * 60 + minute;
}
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    priority_queue<int> pq; // 대실 종료 시각

    sort(book_time.begin(), book_time.end());

    for (int i = 0; i < book_time.size(); i++) {
        int start = stringTimeToInt(book_time[i][0]);
        int end = stringTimeToInt(book_time[i][1]);
        if (!pq.empty() && -pq.top() + 10 <= start) {
            pq.pop();
        }
        pq.push(-end);
        if (answer < pq.size())
            answer = pq.size();
    }

    return answer;
}