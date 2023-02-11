#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> u, vector<int> v) {
    double u_win_percent = min((double)u[0] / (u[1] + 1), 1.0);
    double v_win_percent = min((double)v[0] / (v[1] + 1), 1.0);
    if (u_win_percent == v_win_percent) {
        return u[2] > v[2];
    }
    else return u_win_percent > v_win_percent;
}
int solution(vector<vector<int>> lotteries) {
    int answer = 0;
    for (int i = 0; i < lotteries.size(); i++)
        lotteries[i].push_back(i + 1);  // 복권 번호
    sort(lotteries.begin(), lotteries.end(), cmp);
    answer = lotteries[0][3];

    return answer;
}