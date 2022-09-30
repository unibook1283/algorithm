#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;
    int jobs = progresses.size();
    int max_day = 0;
    for (int i = 0; i < jobs; i++) {
        int left = 100 - progresses[i];
        int day = (left - 1) / speeds[i] + 1;
        days.push(day);
        max_day = max(max_day, day);
    }
    
    for (int i = 1; i <= max_day; i++) {
        int cnt = 0;
        while (!days.empty() && days.front() <= i) {
            days.pop();
            cnt++;
        }
        if (cnt!=0) answer.push_back(cnt);
    }

    return answer;
}
int main() {
    solution({ 93, 30, 55
        }, { 1, 30, 5
        });
    return 0;
}