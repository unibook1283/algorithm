#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<>());
    int n = citations.size();
    for (int i = 0; i < n; i++) {
        int h = citations[i];
        if (i + 1 <= h) {
            answer = i + 1;
        }
        else break;
    }
    return answer;
}