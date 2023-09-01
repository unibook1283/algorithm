#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> total_plays;
    int n = genres.size();
    for (int i = 0; i < n; i++) {
        total_plays[genres[i]] += plays[i];
    }

    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < n; i++) {
        v.push_back({ total_plays[genres[i]], {plays[i], -i} });
    }
    sort(v.begin(), v.end(), greater<>());

    int prev_total_plays = -1;
    bool full = false;
    for (int i = 0; i < n; i++) {
        int total_plays = v[i].first;
        if (total_plays == prev_total_plays) {
            if (full) continue;
            full = true;
        }
        else full = false;
        prev_total_plays = total_plays;
        answer.push_back(-v[i].second.second);
    }

    return answer;
}