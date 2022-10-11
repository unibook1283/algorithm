#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int d[51];
vector<pair<int, int>> v[51];   // (¸ñÀûÁö, cost)
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for (int i = 0; i < road.size(); i++) {
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }

    for (int i = 1; i <= N; i++) {
        d[i] = 987654321;
    }

    priority_queue<pair<int, int>> pq;  // (-cost, node)
    pq.push(make_pair(0, 1));
    d[1] = 0;
    while (!pq.empty()) {
        int c = -pq.top().first;
        int x = pq.top().second;
        pq.pop();
        for (int i = 0; i < v[x].size(); i++) {
            int nx = v[x][i].first;
            int cost = v[x][i].second;
            if (d[nx] > d[x] + cost) {
                d[nx] = d[x] + cost;
                pq.push(make_pair(-d[nx], nx));
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << d[i] << '\n';
        if (d[i] <= K) answer++;
    }

    return answer;
}