#include <iostream>
using namespace std;
char a[5][9];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
pair<int, int> ans = { 987654321,987654321 };	// (핀의 최소 개수, 그 개수를 만들기 위해 필요한 최소 이동 횟수)
int count_pins() {
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if (a[i][j] == 'o') cnt++;
		}
	}
	return cnt;
}
void go(int index) {
	bool finish = true;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if (a[i][j] == 'o') {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || nx >= 5 || ny < 0 || ny >= 9) continue;
					if (a[nx][ny] == 'o') {
						int nnx = nx + dx[k];
						int nny = ny + dy[k];
						if (nnx < 0 || nnx >= 5 || nny < 0 || nny >= 9) continue;
						if (a[nnx][nny] == '.') {
							finish = false;
							a[i][j] = '.';
							a[nx][ny] = '.';
							a[nnx][nny] = 'o';
							go(index + 1);
							a[i][j] = 'o';
							a[nx][ny] = 'o';
							a[nnx][nny] = '.';
						}
					}
				}
			}
		}
	}
	if (finish) {
		int pincnt = count_pins();
		if (pincnt < ans.first) {
			ans = { pincnt,index };
		}
		else if (pincnt == ans.first) {
			if (index < ans.second) {
				ans = { pincnt,index };
			}
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		ans = { 987654321,987654321 };
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> a[i][j];
			}
		}
		go(0);
		cout << ans.first << ' ' << ans.second << '\n';
	}

	return 0;
}