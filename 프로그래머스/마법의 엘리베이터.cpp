#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;

    for (int divisor = 1;; divisor *= 10) {
        if (storey == 0) break;
        int num10 = storey % (10 * divisor);
        int num = num10 / divisor;

        if (num == 5) {
            int num100 = storey % (100 * divisor);
            int num2 = num100 / (divisor * 10);
            if (num2 >= 5) {
                answer += 10 - num;
                storey += 10 * divisor - num10;
            }
            else {
                answer += num;
                storey -= num10;
            }
        }
        else if (num < 5) {
            answer += num;
            storey -= num10;
        }
        else {
            answer += 10 - num;
            storey += 10 * divisor - num10;
        }
    }

    return answer;
}