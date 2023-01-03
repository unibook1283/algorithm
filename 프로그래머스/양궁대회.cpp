#include <iostream>
#include <string>
#include <vector>

using namespace std;

int max_diff = 0;
pair<int, int> answer_lowest = make_pair(11, 11);
vector<int> answer;
int score_diff(vector<int> v, vector<int> info) {
    int ret = 0;
    for (int i = 0; i < 10; i++) {
        if (v[i] > info[i]) ret += 10 - i;
        else if (info[i] != 0 && v[i] <= info[i]) ret -= 10 - i;
    }
    return ret;
}
pair<int, int> cal_lowest(vector<int> v) {
    for (int i = 10; i >= 0; i--) {
        if (v[i] != 0) {
            return make_pair(10 - i, v[i]);
        }
    }
    return make_pair(11, 11);
}
bool is_lower(pair<int, int> lowest, pair<int, int> answer_lowest) {
    if (lowest.first == answer_lowest.first) {
        return lowest.second > answer_lowest.second;
    }
    return lowest.first <= answer_lowest.first;
}
void go(vector<int> v, vector<int> info, int index, int arrow) {
    if (index == 10) {
        v.push_back(arrow); // 남은 화살을 모두 0점에
        int diff = score_diff(v, info);
        if (diff == max_diff) {
            // (가장 낮은 점수, 그 개수)
            pair<int, int> lowest = cal_lowest(v);
            if (is_lower(lowest, answer_lowest)) {
                max_diff = diff;
                answer = v;
                answer_lowest = lowest;
            }
        }
        else if (diff > max_diff) {
            max_diff = diff;
            answer = v;
            answer_lowest = cal_lowest(v);
        }
        return;
    }
    v.push_back(0);
    go(v, info, index + 1, arrow);
    v.pop_back();
    if (arrow > info[index]) {
        v.push_back(info[index] + 1);
        go(v, info, index + 1, arrow - (info[index] + 1));
        v.pop_back();
    }
}
vector<int> solution(int n, vector<int> info) {

    vector<int> v;
    go(v, info, 0, n);
    if (max_diff == 0) {
        vector<int> u(1, -1);
        return u;
    }
    return answer;
}