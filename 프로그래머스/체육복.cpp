#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int check[33];
int borrow(int n) {
    for (int i = n - 1; i <= n + 1; i++) {
        if (check[i] > 0) {
            check[i]--;
            return 1;
        }
    }
    return 0;
}
int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    int answer = n - lost.size();
    for (int i = 0; i < reserve.size(); i++) {
        check[reserve[i]]++;
    }

    int cnt = 0;
    for (int i = 0; i < lost.size(); i++) {
        if (check[lost[i]] > 0) {
            check[lost[i]]--;
            lost.erase(lost.begin() + i);
            i--;
            cnt++;
        }
    }

    for (int i = 0; i < lost.size(); i++) {
        cnt += borrow(lost[i]);
    }
    answer += cnt;

    return answer;
}