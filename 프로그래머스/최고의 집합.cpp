#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    int q = s / n;
    int r = s % n;
    if (q == 0) return { -1 };
    vector<int> answer(n, q);
    for (int i = n - r; i < n; i++) {
        answer[i]++;
    }

    return answer;
}