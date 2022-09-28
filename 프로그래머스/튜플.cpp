#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool check[100001];
vector<int> solution(string s) {
    vector<int> answer;
    int n = 0;
    vector<pair<int, vector<int>>> v;
    vector<int> temp;
    for (int i = 1; i < s.size() - 1; i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            n *= 10;
            n += s[i] - '0'; 
        }
        else if (s[i] == ',') {
            if (s[i - 1] == '}') continue;
            temp.push_back(n);
            n = 0;
        }
        else if (s[i] == '}') {
            temp.push_back(n);
            n = 0;
            v.push_back(make_pair(temp.size(), temp));
            temp.clear();
        }
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        int n = v[i].first;
        vector<int> temp = v[i].second;
        for (int j = 0; j < n; j++) {
            int num = temp[j];
            if (!check[num]) {
                check[num] = true;
                answer.push_back(num);
            }
        }
    }
    return answer;
}
int main() {
    solution("{{1,2,3},{2,1},{1,2,4,3},{2}}");

    return 0;
}