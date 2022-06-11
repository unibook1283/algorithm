#include <iostream>
using namespace std;
int a[1001][1001];
int dkx[] = { -2,-2,-1,-1,1,1,2,2 };
int dky[] = { -1,1,-2,2,-2,2,-1,1 };
int dqx[] = { -1,-1,-1,0,0,1,1,1 };
int dqy[] = { -1,0,1,-1,1,-1,0,1 };
int main() {
	int n, m;
	cin >> n >> m;
	int q, k, p;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		a[x][y] = 1;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		a[x][y] = 2;
	}
	cin >> p;
	for (int i = 0; i < p; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		a[x][y] = 3;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 2) {
				for (int k = 0; k < 8; k++) {
					int nx = i + dkx[k];
					int ny = j + dky[k];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
						if (a[nx][ny] == 0) a[nx][ny] = -1;
					}
				}
			}
			else if (a[i][j] == 1) {
				for (int k = 0; k < 8; k++) {
					int nx = i;
					int ny = j;
					while (1) {
						nx += dqx[k];
						ny += dqy[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
							if (a[nx][ny] == 0 || a[nx][ny] == -1) a[nx][ny] = -1;
							else break;
						}
						else break;
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}