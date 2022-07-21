#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    sort(rocks.begin(), rocks.end());

    long long left = 1, right = 1000000000;
    while (left <= right) {
        long long prev = 0;
        long long mid = (left + right) / 2;
        int cnt = 0;
        for (int i = 0; i < rocks.size(); i++) {
            long long d = rocks[i] - prev;
            if (d < mid) {
                cnt++;
                continue;
            }
            prev = rocks[i];
        }
        if (distance - prev < mid) cnt++;
        if (cnt > n) {
            right = mid - 1;
        }
        else {
            if (answer < mid) answer = mid;
            left = mid + 1;
        }
    }

    return answer;
}