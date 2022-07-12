#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
    bool operator() (int x, int y) {
        return x > y;
    }
};
int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, cmp> pq;
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }


    return answer;
}