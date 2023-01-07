#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> v[20];
int answer = 0;
void dfs(int x, int sheep, int wolf, vector<int> cand, vector<int> info) {
    if (sheep <= wolf) return;
    for (int i = 0; i < cand.size(); i++) {
        int nx = cand[i];
        if (nx == -1) continue;
        cand[i] = -1;
        int cnt = 0;
        for (int j = 0; j < v[nx].size(); j++) {
            cand.push_back(v[nx][j]);
            cnt++;
        }
        dfs(nx, info[nx] == 0 ? sheep + 1 : sheep, info[nx] == 1 ? wolf + 1 : wolf, cand, info);
        for (int j = 0; j < cnt; j++)
            cand.pop_back();
        cand[i] = nx;
    }
    answer = max(answer, sheep);
}
int solution(vector<int> info, vector<vector<int>> edges) {
    for (int i = 0; i < edges.size(); i++) {
        v[edges[i][0]].push_back(edges[i][1]);
    }

    vector<int> cand;
    for (int i = 0; i < v[0].size(); i++) {
        cand.push_back(v[0][i]);
    }
    dfs(0, 1, 0, cand, info);

    return answer;
}