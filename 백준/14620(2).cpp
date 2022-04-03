#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int a[10][10];
bool c[10][10];
vector<pair<int, int>> v, f;
int n;
int dx[] = { 0,0,1,-1,0 };
int dy[] = { 1,-1,0,0,0 };
int ans = 987654321;
int cal(vector<pair<int, int>> f) {
	memset(c, false, sizeof(c));
	int cost = 0;
	for (int i = 0; i < 3; i++) {
		int x = f[i].first;
		int y = f[i].second;
		//cout << "(" << x << ", " << y << ") ";
		for (int j = 0; j < 5; j++) {
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (c[nx][ny] == true) return -1;	// 다른 꽃과 겹치면 return -1
			c[nx][ny] = true;
			cost += a[nx][ny];
		}
	}
	return cost;
}
void go(vector<pair<int,int>> f, int index) {
	if (f.size() == 3) {
		int cost = cal(f);
		if (cost == -1) return;
		else {
			ans = min(ans, cost);
			return;
		}
	}
	for (int i = index; i < v.size(); i++) {
		f.push_back(v[i]);
		go(f, i + 1);
		f.pop_back();
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			// 가장자리가 아니라면 그 좌표를 v에 넣어줌.
			if (i != 0 && j != 0 && i != n - 1 && j != n - 1) {
				v.push_back(make_pair(i, j));
			}
		}
	}
	go(f, 0);
	cout << ans;

	return 0;
}