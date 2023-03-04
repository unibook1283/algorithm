#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;

    int end = 0;
    for (int i = 0; i < section.size(); i++) {
        if (end <= section[i]) {
            answer++;
            end = section[i] + m;
            if (end > n) break;
        }
    }

    return answer;
}