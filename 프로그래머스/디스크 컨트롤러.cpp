#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int, int>> pq;  // (-duration, start)
    int j = 0, endTime = 0, sum = 0;

    sort(jobs.begin(), jobs.end());

    while (j < jobs.size() || !pq.empty()) {
        if (j < jobs.size() && jobs[j][0] <= endTime) {
            pq.push({ -jobs[j][1], jobs[j][0] });
            j++;
            continue;
        }
        if (!pq.empty()) {
            endTime += -pq.top().first;
            sum += endTime - pq.top().second;
            pq.pop();
        }
        else {
            endTime = jobs[j][0];
        }
    }
    answer = sum / jobs.size();

    return answer;
}