#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long pSum[500001];
long long solution(vector<int> sequence) {
    long long answer = -98765432100000;
    int n = sequence.size();
    int mul = 1;
    for (int i = 0; i < n; i++, mul *= -1) {
        pSum[i + 1] = pSum[i] + mul * sequence[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n + 1; j++) {
            answer = max(answer, abs(pSum[j] - pSum[i]));
        }
    }

    return answer;
}