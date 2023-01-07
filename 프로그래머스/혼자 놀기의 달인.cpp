#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int go(int x, int start, vector<int> cards, vector<bool>& check) {
    check[x] = true;
    if (cards[x] == start) return 1;
    return 1 + go(cards[x], start, cards, check);
}
int solution(vector<int> cards) {
    int answer = 0;
    vector<bool> check(cards.size());

    for (int i = 0; i < cards.size(); i++)
        cards[i]--;

    vector<int> res;
    for (int i = 0; i < cards.size(); i++) {
        if (!check[i]) {
            int cnt = go(i, i, cards, check);
            res.push_back(cnt);
        }
    }
    if (res.size() == 1) return 0;
    sort(res.begin(), res.end(), greater<>());
    answer = res[0] * res[1];

    return answer;
}