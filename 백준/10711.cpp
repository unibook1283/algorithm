#include <iostream>
#include <queue>
using namespace std;
int h, w;
int a[1001][1001];
int dx[] = { 1,1,1,0,0,-1,-1,-1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
queue<pair<int, int>> q;
int main() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char ch;
			cin >> ch;
			if (ch == '.') {
				q.push({ i,j });
				a[i][j] = -1;
			}
			else {
				a[i][j] = ch - '0';
			}
		}
	}

	int ans = 0;
	while (1) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int j = 0; j < 8; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
					a[nx][ny]--;
					if (a[nx][ny] == 0) {
						q.push({ nx,ny });
					}
				}
			}
		}
		if (q.empty()) break;
		ans++;
	}
	cout << ans << '\n';

	return 0;
}