#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int n;
int cache[2][100000];
bool is_palindrome(vector<int> v) {
    int left = 0, right = v.size() - 1;
    while (left < right) {
        if (v[left++] != v[right--]) return false;
    }
    return true;
}
int vec_to_int(vector<int> v) {
    int ret = 0;
    for (int i = 0; i < v.size(); i++) {
        ret += v[i] * pow(10, v.size() - i - 1);
    }
    return ret;
}
int go(int turn, vector<int>& query) {
    if (is_palindrome(query)) {
        return turn;
    }
    int q_int = vec_to_int(query);
    int& ret = cache[turn][q_int];
    if (ret != -1) return ret;
    if (turn) {
        ret = 1;
        for (int i = 0; i < n; i++) {
            if (query[i] > 0) {
                query[i]--;
                ret = min(ret, go(!turn, query));
                query[i]++;
            }
        }
        return ret;
    }
    else {
        ret = 0;
        for (int i = 0; i < n; i++) {
            if (query[i] > 0) {
                query[i]--;
                ret = max(ret, go(!turn, query));
                query[i]++;
            }
        }
        return ret;
    }
}
vector<int> solution(vector<vector<int>> queries) {
    memset(cache, -1, sizeof(cache));
    vector<int> answer;
    n = queries[0].size();
    for (int i = 0; i < queries.size(); i++) {
        answer.push_back(go(0, queries[i]));
    }

    return answer;
}