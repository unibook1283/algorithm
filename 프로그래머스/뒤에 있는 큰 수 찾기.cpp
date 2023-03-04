#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    priority_queue<pair<int, int>> pq;  // (-value, index)

    for (int i = 0; i < numbers.size(); i++) {
        int number = numbers[i];
        while (!pq.empty() && -pq.top().first < number) {
            answer[pq.top().second] = number;
            pq.pop();
        }
        pq.push({ -number, i });
    }
    while (!pq.empty()) {
        answer[pq.top().second] = -1;
        pq.pop();
    }

    return answer;
}