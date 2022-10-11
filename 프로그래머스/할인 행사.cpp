#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> m;
    for (int i = 0; i < want.size(); i++) {
        m[want[i]] = number[i];
    }

    for (int i = 0; i <= discount.size() - 10; i++) {
        bool end = false;
        map<string, int> ma;
        ma = m;
        for (int j = 0; j < 10; j++) {
            if (--ma[discount[i + j]] < 0) {
                end = true;
                break;
            }
        }
        if (end) continue;
        for (auto iter = ma.begin(); iter != ma.end(); iter++) {
            if (iter->second > 0) {
                end = true;
                break;
            }
        }
        if (end) continue;
        answer++;
    }

    return answer;
}