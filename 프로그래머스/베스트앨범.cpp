#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> m;
    int n = genres.size();
    for (int i = 0; i < n; i++) {
        string genre = genres[i];
        int play = plays[i];
        m[genre] += play;
    }

    map<int, string> rm;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        rm[iter->second] = iter->first;
    }
    for (auto iter = rm.rbegin(); iter != rm.rend(); iter++) {
        string genre = iter->second;
        vector<pair<int, int>> v; // (play, index)
        for (int i = 0; i < n; i++) {
            if (genres[i] == genre) v.push_back(make_pair(plays[i], -i));
        }
        sort(v.begin(), v.end(), greater<>());
        answer.push_back(-v[0].second);
        if (v.size() > 1) answer.push_back(-v[1].second);
    }

    return answer;
}