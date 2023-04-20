#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
char a[501][501];
int sx, sy, ex, ey;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, h, d;
const int INF = 987654321;
vector<pair<int, int>> umbrella;
int go(int x, int y, int u_index, int health, int u_count) {
	int edist = abs(x - ex) + abs(y - ey);
	if (edist <= health + u_count) {
		return edist;
	}
	if (u_index == umbrella.size()) {
		return INF;
	}
	int ux = umbrella[u_index].first;
	int uy = umbrella[u_index].second;
	int udist = abs(x - ux) + abs(y - uy);
	health -= max(udist - u_count, 0);
	if (health < 0) return INF;
	u_count = max(0, u_count - udist);
	return udist + go(ux, uy, u_index + 1, health, d);
}
int main() {
	cin >> n >> h >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'S') {
				sx = i; sy = j;
			}
			else if (a[i][j] == 'E') {
				ex = i; ey = j;
			}
			else if (a[i][j] == 'U') {
				umbrella.push_back({ i,j });
			}
		}
	}

	int answer = INF;
	sort(umbrella.begin(), umbrella.end());
	do {
		int res = go(sx, sy, 0, h, 0);
		answer = min(answer, res);
	} while (next_permutation(umbrella.begin(), umbrella.end()));

	if (answer == INF) cout << "-1\n";
	else cout << answer << '\n';

	return 0;
}