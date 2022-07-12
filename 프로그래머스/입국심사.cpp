#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 1000000000;

    sort(times.begin(), times.end());

    long long left = 1, right = (long long) n * times[times.size() - 1];
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long cnt = 0;
        for (int i = 0; i < times.size(); i++) {
            cnt += mid / times[i];
        }
        if (cnt >= n) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return answer;
}