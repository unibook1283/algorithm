#include <iostream>
#include <string>
#include <vector>

using namespace std;

int graph[201][201];
const int INF = 987654321;
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }

    for (int i = 0; i < fares.size(); i++) {
        int c = fares[i][0];
        int d = fares[i][1];
        int f = fares[i][2];
        graph[c][d] = f;
        graph[d][c] = f;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }

    int answer = INF;
    for (int i = 1; i <= n; i++) {  // i±îÁö ÇÕ½Â
        if (graph[s][i] == INF || graph[i][a] == INF || graph[i][b] == INF)
            continue;
        int cost = graph[s][i] + graph[i][a] + graph[i][b];
        answer = min(answer, cost);
    }

    return answer;
}