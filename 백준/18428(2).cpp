#include <iostream>
#include <vector>
using namespace std;
char a[6][6];
vector<pair<int, int>> x, t;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n;
bool can_avoid(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int tx = x;
		int ty = y;
		while (tx >= 0 && tx < n && ty >= 0 && ty < n) {
			if (a[tx][ty] == 'S') return false;
			if (a[tx][ty] == 'O') break;
			tx += dx[i];
			ty += dy[i];
		}
	}
	return true;
}
void go(int index, int cnt) {
	if (cnt == 3) {
		for (auto a : t) {
			if (!can_avoid(a.first, a.second)){
				return;
			}
		}
		cout << "YES";
		exit(0);
	}
	for (int i = index; i < x.size(); i++) {
		a[x[i].first][x[i].second] = 'O';
		go(i + 1, cnt + 1);
		a[x[i].first][x[i].second] = 'X';
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'X') {
				x.push_back(make_pair(i, j));
			}
			else if (a[i][j] == 'T') {
				t.push_back(make_pair(i, j));
			}
		}
	}
	go(0, 0);
	cout << "NO";

	return 0;
}