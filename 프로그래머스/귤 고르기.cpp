#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    map<int, int> m;
    for (int i = 0; i < tangerine.size(); i++) {
        m[tangerine[i]]++;
    }
    vector<int> v;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        v.push_back(iter->second);
    }
    sort(v.begin(), v.end(), greater<>());
    int i;
    for (i = 0; i < v.size(); i++) {
        k -= v[i];
        if (k <= 0) break;
    }

    return i + 1;
}