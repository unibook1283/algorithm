#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int> pq;
    int round;
    for (round = 0; round < enemy.size(); round++) {
        if (pq.size() < k) pq.push(-enemy[round]);
        else {
            if (-pq.top() >= enemy[round]) {
                if (n < enemy[round]) break;
                else n -= enemy[round];
            }
            else {
                if (n < -pq.top()) {
                    break;
                }
                else {
                    n -= -pq.top();
                    pq.pop();
                    pq.push(-enemy[round]);
                }
            }
        }
    }

    return round;
}