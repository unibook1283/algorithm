#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> the_time;
void get_the_time(int from, int to, int work_time, int break_time) {
    int time = 0;
    while (time < to) {
        time += work_time;
        if (time >= from) {
            the_time.push_back(from);
            break;
        }
        time += break_time;
        if (time + 1 >= from && time + 1 <= to) {
            the_time.push_back(time + 1);
            break;
        }
    }
}
int solution(int distance, vector<vector<int>> scope, vector<vector<int>> times) {
    int answer = distance;
    for (int i = 0; i < scope.size(); i++) {
        int from = min(scope[i][0], scope[i][1]);
        int to = max(scope[i][0], scope[i][1]);
        int work_time = times[i][0];
        int break_time = times[i][1];
        get_the_time(from, to, work_time, break_time);
    }
    sort(the_time.begin(), the_time.end());
    if (!the_time.empty())
        answer = the_time[0];

    return answer;
}