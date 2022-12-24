#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> u, pair<int, int> v) {
    return u.second < v.second;
}
int solution(vector<int> food_times, long long k) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = food_times.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back(make_pair(food_times[i], i + 1));
    }
    sort(v.begin(), v.end());

    int prev_time = 0;
    int i;
    for (i = 0; i < n; i++) {
        int cur_time = v[i].first;
        int time_dif = cur_time - prev_time;
        if (time_dif == 0) continue;
        prev_time = cur_time;
        long long spend = (long long)time_dif * (n - i);
        if (spend <= k) {
            k -= spend;
        }
        else {
            k %= n - i;
            sort(v.begin() + i, v.end(), cmp);
            return v[i + k].second;
        }
    }
    return -1;
}