#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> REQS;
int answer = 987654321;
int cal_total_waiting_time(vector<int> mentor_count) {
    vector<priority_queue<int>> pq_vector(mentor_count.size());
    int total_waiting_time = 0;
    for (vector<int> req : REQS) {
        int start_time = req[0];
        int duration = req[1];
        int mentor_index = req[2] - 1;
        priority_queue<int>& pq = pq_vector[mentor_index];
        int prev_end_time = 0;
        if (pq.size() == mentor_count[mentor_index]) {
            prev_end_time = -pq.top();
            pq.pop();
            if (start_time < prev_end_time)
                total_waiting_time += prev_end_time - start_time;
        }
        pq.push(-(max(prev_end_time, start_time) + duration));
    }
    return total_waiting_time;
}
void go(vector<int> mentor_count, int prev, int left_mentor_count) {
    if (left_mentor_count == 0) {
        answer = min(answer, cal_total_waiting_time(mentor_count));
        return;
    }
    for (int i = 0; i < mentor_count.size(); i++) {
        if (prev <= i) {
            mentor_count[i]++;
            go(mentor_count, i, left_mentor_count - 1);
            mentor_count[i]--;
        }
    }
}
int solution(int k, int n, vector<vector<int>> reqs) {
    REQS = reqs;
    vector<int> mentor_count(k, 1);
    go(mentor_count, -1, n - k);

    return answer;
}