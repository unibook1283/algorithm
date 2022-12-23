#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
int refer[10001];

void share_profit(int x, int amount, vector<int>& answer) {
    int share_amount = amount / 10;
    answer[x] += amount - share_amount;
    int nx = refer[x];
    if (nx == -1) return;
    share_profit(nx, share_amount, answer);
}
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size());
    map<string, int> name_index;
    for (int i = 0; i < enroll.size(); i++) {
        string name = enroll[i];
        name_index[name] = i;
    }

    for (int i = 0; i < referral.size(); i++) {
        if (referral[i] != "-") {
            refer[i] = name_index[referral[i]];
        }
        else refer[i] = -1;
    }

    for (int i = 0; i < seller.size(); i++) {
        share_profit(name_index[seller[i]], amount[i] * 100, answer);
    }

    return answer;
}