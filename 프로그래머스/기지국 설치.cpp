#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    int cur = 1, index = 0;
    while (cur <= n) {
        if (stations[index] - w <= cur && cur <= stations[index] + w) {
            cur = stations[index++] + w;
        }
        else {
            cur += 2 * w;
            answer++;
        }
        cur++;
    }

    return answer;
}