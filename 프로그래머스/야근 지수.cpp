#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for (int i = 0; i < works.size(); i++) {
        pq.push(works[i]);
    }

    while (n--) {
        int x = pq.top();
        if (x == 0) return 0;
        pq.pop();
        pq.push(x - 1);
    }
    
    while (!pq.empty()) {
        int x = pq.top();
        pq.pop();
        answer += x * x;
    }

    return answer;
}