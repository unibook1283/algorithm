#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, p;
char a[1001][1001];
bool check[1001][1001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int dps[26];
int bossHp;
void attack(vector<int> attacker) {
	for (int i = 0; i < attacker.size(); i++) {
		int damage = dps[attacker[i]];
		bossHp -= damage;
	}
}
int bfs(int x, int y) {
	vector<int> attacker;
	check[x][y] = true;
	queue<pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			x = q.front().first;
			y = q.front().second;
			q.pop();
			if ('a' <= a[x][y] && a[x][y] <= 'z')
				attacker.push_back(a[x][y] - 'a');
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (a[nx][ny] != 'X' && !check[nx][ny]) {
						check[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		attack(attacker);
		if (bossHp <= 0) {
			return attacker.size();
		}
	}
	return attacker.size();
}
int main() {
	cin >> n >> m >> p;
	int sx = -1, sy = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'B') {
				sx = i;
				sy = j;
			}
		}
	}
	for (int i = 0; i < p; i++) {
		char player;
		int damage;
		cin >> player >> damage;
		dps[player - 'a'] = damage;
	}
	cin >> bossHp;
	cout << bfs(sx, sy) << '\n';

	return 0;
}