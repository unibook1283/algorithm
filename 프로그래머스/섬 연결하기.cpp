#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int parent[101];
vector<pair<int, int>> graph[101];  // (¸ñÀûÁö, cost)
int get_parent(int x) {
    if (x == parent[x]) return x;
    return get_parent(parent[x]);
}
void union_parent(int x, int y) {
    x = get_parent(x);
    y = get_parent(y);
    if (x > y) parent[y] = x;
    else parent[x] = y;
}
bool same_parent(int x, int y) {
    if (get_parent(x) == get_parent(y)) return true;
    return false;
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    vector<pair<int, pair<int, int>>> v;    // (cost, a, b)
    for (int i = 0; i < costs.size(); i++) {
        int a = costs[i][0];
        int b = costs[i][1];
        int cost = costs[i][2];
        v.push_back(make_pair(cost, make_pair(a, b)));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        int cost = v[i].first;
        int a = v[i].second.first;
        int b = v[i].second.second;
        if (!same_parent(a, b)) {
            union_parent(a, b);
            answer += cost;
        }
    }

    return answer;
}