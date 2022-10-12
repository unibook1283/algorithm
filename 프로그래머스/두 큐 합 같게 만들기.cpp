#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int n = queue1.size();
    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    if ((sum1 + sum2) % 2 != 0) return -1;
    int index1 = 0, index2 = 0;
    while (1) {
        if (sum1 == sum2) break;
        else if (sum1 > sum2) {
            int num = queue1[index1++];
            queue2.push_back(num);
            sum1 -= num;
            sum2 += num;
        }
        else {
            int num = queue2[index2++];
            queue1.push_back(num);
            sum1 += num;
            sum2 -= num;
        }
        answer++;
        if (answer > 4 * n) {
            answer = -1;
            break;
        }
    }

    return answer;
}