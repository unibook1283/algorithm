#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left = 0, right = 0;
    for (int i = 0; i < stones.size(); i++) {
        right = max(right, stones[i]);
    }
    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = 0;
        bool ok = true;
        for (int i = 0; i < stones.size(); i++) {
            if (stones[i] <= mid) {
                cnt++;
            }
            else {
                if (cnt >= k) {
                    ok = false;
                    break;
                }
                cnt = 0;
            }
        }
        if (cnt >= k) ok = false;
        if (ok) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return answer + 1;
}