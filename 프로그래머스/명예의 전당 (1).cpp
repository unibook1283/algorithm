#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int> pq;

    for (int i = 0; i < score.size(); i++) {
        int s = score[i];
        if (pq.size() < k) pq.push(-s);
        else {
            int t = -pq.top();
            if (t < s) {
                pq.pop();
                pq.push(-s);
            }
        }
        answer.push_back(-pq.top());
    }

    return answer;
}