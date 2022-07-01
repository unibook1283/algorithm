#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
int map[11][11];
int a[11][11];
vector<int> trees[11][11];	// 나무의 나이를 저장
vector<tuple<int, int, int>> dead;	// 죽은 나무들 (x, y, age)
int n, m, k;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
void spring() {	// 문제 : trees 나이순 정렬을 어떻게 할지.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sort(trees[i][j].begin(), trees[i][j].end());
			for (int k = 0; k < trees[i][j].size(); k++) {
				if (trees[i][j][k] <= map[i][j]) {
					map[i][j] -= trees[i][j][k];
					trees[i][j][k]++;
				}
				else {
					dead.push_back(make_tuple(i, j, trees[i][j][k]));
					trees[i][j].erase(trees[i][j].begin() + k);
				}
			}
		}
	}
}
void summer() {
	for (auto t : dead) {
		int x, y, age;
		tie(x, y, age) = t;
		map[x][y] += age / 2;
	}
}
void reproduce(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			trees[nx][ny].push_back(1);
		}
	}
}
void fall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < trees[i][j].size(); k++) {
				if (trees[i][j][k] % 5 == 0) {
					reproduce(i, j);
				}
			}
		}
	}
}
void winter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] += a[i][j];
		}
	}
}
int count() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cnt += trees[i][j].size();
		}
	}
	return cnt;
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			map[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, age;
		cin >> x >> y >> age;
		x--; y--;
		trees[x][y].push_back(age);
	}
	while (k--) {
		spring();
		summer();
		fall();
		winter();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << map[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	cout << count() << '\n';



	return 0;
}