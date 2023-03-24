#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> graph[100001];
int d[100001];
void bfs(int x) {
    d[x] = 0;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        x = q.front();
        q.pop();
        for (int i = 0; i < graph[x].size(); i++) {
            int nx = graph[x][i];
            if (d[nx] == -1) {
                d[nx] = d[x] + 1;
                q.push(nx);
            }
        }
    }
}
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    for (int i = 0; i < roads.size(); i++) {
        int a = roads[i][0];
        int b = roads[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    memset(d, -1, sizeof(d));
    bfs(destination);

    for (int i = 0; i < sources.size(); i++)
        answer.push_back(d[sources[i]]);

    return answer;
}