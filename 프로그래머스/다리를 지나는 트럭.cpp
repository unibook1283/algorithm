#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;

    int index = 0;
    int cur_weight = 0;
    int pass_cnt = 0;
    while (++answer) {
        if (q.size() == bridge_length) {
            if (q.front() != 0) {
                pass_cnt++;
                cur_weight -= q.front();
                if (pass_cnt == truck_weights.size()) break;
            }
            q.pop();
        }
        int truck_weight = (index == truck_weights.size()) ? 10001 : truck_weights[index];
        if (cur_weight + truck_weight <= weight) {
            q.push(truck_weight);
            cur_weight += truck_weight;
            index++;
        }
        else {
            q.push(0);
        }
    }

    return answer;
}
