#include <iostream>
using namespace std;
int a[23][23];		// 0 : 아직 수확하지 않은 사과나무,  1 : 돌 또는 수확한 사과나무
int ans = 0;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool harvest_all() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (a[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}
void go(int x, int y) {
	if (x == 4 && y == 4) {
		if (harvest_all()) {
			ans++;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
			if (a[nx][ny] == 0) {
				a[nx][ny] = 1;
				
				go(nx, ny);
				a[nx][ny] = 0;
			}
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		a[x][y] = 1;
	}
	a[0][0] = 1;
	go(0, 0);

	cout << ans << '\n';

	return 0;
}