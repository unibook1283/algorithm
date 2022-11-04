#include <iostream>
using namespace std;
char a[5][5];
int mini = 987654321, maxi = -987654321;
int dx[] = { 1,0 };
int dy[] = { 0,1 };
int n;
void go(int x, int y, int val) {
	if (x == n - 1 && y == n - 1) {
		mini = min(mini, val);
		maxi = max(maxi, val);
		return;
	}
	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			int nv = val;
			if (a[x][y] == '-') nv -= a[nx][ny] - '0';
			else if (a[x][y] == '+') nv += a[nx][ny] - '0';
			else if (a[x][y] == '*') nv *= a[nx][ny] - '0';
			go(nx, ny, nv);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	go(0, 0, a[0][0] - '0');
	cout << maxi << ' ' << mini << '\n';

	return 0;
}