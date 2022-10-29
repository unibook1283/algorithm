#include <iostream>
using namespace std;
int a[21][21];
int n, m;
int type[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};
bool cover(int x, int y, int k, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		int nx = x + type[k][i][0];
		int ny = y + type[k][i][1];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if ((a[nx][ny] += delta) > 1) ok = false;
		}
		else ok = false;
	}
	return ok;
}
int go() {
	int x = -1, y = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				x = i;
				y = j;
				break;
			}
		}
		if (x != -1) break;
	}
	if (x == -1) return 1;
	int cnt = 0;
	for (int k = 0; k < 4; k++) {
		if (cover(x, y, k, 1)) {
			cnt += go();
		}
		cover(x, y, k, -1);
	}
	return cnt;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int cnt = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char ch;
				cin >> ch;
				if (ch == '.') {
					a[i][j] = 0;
					cnt++;
				}
				else {
					a[i][j] = 1;
				}
			}
		}
		if (cnt % 3 != 0) {
			cout << "0\n";
			continue;
		}
		cout << go() << '\n';
	}

	return 0;
}