#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < routes.size(); i++) {
        pq.push(make_pair(-routes[i][1], routes[i][0]));
    }
    
    int cur_end = -pq.top().first;
    answer++;
    while (!pq.empty()) {
        int from = pq.top().second;
        int to = -pq.top().first;
        pq.pop();
        if (cur_end > to) {
            cur_end = to;
            answer++;
        }
    }

    return answer;
}