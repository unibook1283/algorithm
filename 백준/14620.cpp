#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[10][10];
bool check[10][10];
int n;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int calculate(int x, int y) {
	check[x][y] = true;
	int res = a[x][y];
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) return -1;
		if (check[nx][ny]) return -1;
		check[nx][ny] = true;
		res += a[nx][ny];
	}
	return res;
}
int plant(vector<int>& v) {
	int sum = 0;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (v[(i - 1) * (n - 2) + (j - 1)]) {
				int cost = calculate(i, j);
				if (cost == -1) return -1;
				sum += cost;
			}
		}
	}
	return sum;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	vector<int> v;
	for (int i = 0; i < (n - 2) * (n - 2) - 3; i++) {
		v.push_back(0);
	}
	for (int i = 0; i < 3; i++) {
		v.push_back(1);
	}

	int ans = 987654321;
	do {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				check[i][j] = false;
			}
		}
		int res = plant(v);
		if (res != -1) ans = min(ans, res);
	} while (next_permutation(v.begin(), v.end()));
	cout << ans;


	return 0;
}