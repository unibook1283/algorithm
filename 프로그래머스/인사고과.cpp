#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int ranks[100001];
int solution(vector<vector<int>> scores) {
    int answer = 0;
    memset(ranks, -1, sizeof(ranks));

    for (int i = 0; i < scores.size(); i++) {
        scores[i][0] = -socres[i][0];
        scores[i].push_back(i);
    }

    sort(scores.begin(), scores.end());

    vector<pair<int, int>> filtered; // (sum, index)
    int maxSecond = 0;
    for (int i = 0; i < scores.size(); i++) {
        if (scores[i][1] >= maxSecond) {
            maxSecond = scores[i][1];
            int sum = scores[i][0] + scores[i][1];
            filtered.push_back({ -sum, scores[i][2] });
        }
    }

    sort(filtered.begin(), filtered.end());

    int prevSum = -1;
    int prevRank = -1;
    int curRank = 1;
    for (int i = 0; i < filtered.size(); i++) {
        int sum = -filtered[i].first;
        int index = filtered[i].second;
        if (sum == prevSum) {
            ranks[index] = prevRank;
        }
        else {
            ranks[index] = curRank;
            prevRank = curRank;
        }
        curRank++;
        prevSum = sum;
    }

    answer = ranks[0];

    return answer;
}