#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int a[50][50];
bool check[50][50];
int cplus[50][50] = { 0, };
int dx[] = { 0,-1,-1,-1,0,1,1,1	};
int dy[] = { -1,-1,0,1,1,1,0,-1 };
int n, m;
void copy_water(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[2 * i + 1];
		int ny = y + dy[2 * i + 1];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (a[nx][ny] != 0) {
				cplus[x][y]++;
			}
		}
	}
}
void plus_water(int x, int y) {
	a[x][y] += cplus[x][y];
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	vector<pair<int, int>> cloud;
	cloud.push_back(make_pair(n - 2, 0));
	cloud.push_back(make_pair(n - 1, 0));
	cloud.push_back(make_pair(n - 2, 1));
	cloud.push_back(make_pair(n - 1, 1));

	while (m--) {
		int d, s;
		cin >> d >> s;
		d--;

		memset(check, false, sizeof(check));
		memset(cplus, 0, sizeof(cplus));
		int dsx = dx[d] * s;
		int dsy = dy[d] * s;
		for (int j = 0; j < cloud.size(); j++) {
			int x = cloud[j].first;
			int y = cloud[j].second;
			x += dsx;
			y += dsy;
			while (x < 0) x += n;
			while (y < 0) y += n;
			x %= n;
			y %= n;
			cloud[j].first = x;
			cloud[j].second = y;
			check[x][y] = true;
			a[x][y]++;
		}
		for (int j = 0; j < cloud.size(); j++) {
			int x = cloud[j].first;
			int y = cloud[j].second;
			copy_water(x, y);
			plus_water(x, y);
		}
		cloud.clear();
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (a[j][k] >= 2 && check[j][k] == false) {
					cloud.push_back(make_pair(j, k));
					a[j][k] -= 2;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += a[i][j];
		}
	}
	cout << ans << '\n';
	
	return 0;
}