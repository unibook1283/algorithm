#include <iostream>
#include <cstring>
using namespace std;
int n, m;
char a[16][16];
bool check[16][16];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int getMaximalMultiply(int x1, int y1, int x2, int y2) {
	int nx[2][4] = { {x1,x1,x1,x1}, {x2,x2,x2,x2} };
	int ny[2][4] = { {y1,y1,y1,y1}, {y2,y2,y2,y2} };
	int crossLength[2] = { 0, };
	bool finish[2] = { false, false };
	check[x1][y1] = true;
	check[x2][y2] = true;
	while (1) {
		for (int i = 0; i < 2; i++) {
			if (finish[i]) continue;
			for (int j = 0; j < 4; j++) {
				nx[i][j] += dx[j];
				ny[i][j] += dy[j];
				if (nx[i][j] < 0 || nx[i][j] >= n || ny[i][j] < 0 || ny[i][j] >= m) {
					finish[i] = true;
					break;
				}
				if (a[nx[i][j]][ny[i][j]] == '.' || check[nx[i][j]][ny[i][j]]) {
					finish[i] = true;
					break;
				}
				check[nx[i][j]][ny[i][j]] = true;
			}
			if (!finish[i])
				crossLength[i]++;
		}
		if (finish[0] && finish[1]) break;
	}
	return (crossLength[0] * 4 + 1) * (crossLength[1] * 4 + 1);
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int ans = 0;
	for (int x1 = 0; x1 < n; x1++) {
		for (int y1 = 0; y1 < m; y1++) {
			if (a[x1][y1] == '.') continue;
			for (int x2 = 0; x2 < n; x2++) {
				for (int y2 = 0; y2 < m; y2++) {
					if (a[x2][y2] == '.') continue;
					if (x1 == x2 && y1 == y2) continue;
					memset(check, false, sizeof(check));
					int maxi = getMaximalMultiply(x1, y1, x2, y2);
					ans = max(ans, maxi);
				}
			}
		}
	}
	cout << ans << '\n';

	return 0;
}