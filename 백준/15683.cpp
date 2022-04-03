#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
int n, m;
int a[8][8];
int copy_a[8][8];
vector<pair<int, int>> cctv;
vector<int> dir;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans = 987654321;
int count_blind_spot() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copy_a[i][j] == 0) cnt++;
		}
	}

	return cnt;
}
void set_one(int x, int y, int direction) {
	int nx = x + dx[direction];
	int ny = y + dy[direction];
	while (a[nx][ny] != 6 && nx >= 0 && nx < n && ny >= 0 && ny < m) {
		copy_a[nx][ny] = -1;
		nx += dx[direction];
		ny += dy[direction];
	}
}
void set_cctv_area() {
	copy(&a[0][0], &a[0][0] + 64, &copy_a[0][0]);
	for (int i = 0; i < cctv.size(); i++) {
		int x = cctv[i].first;
		int y = cctv[i].second;
		if (a[x][y] == 1) {
			set_one(x, y, dir[i]);
		}
		else if (a[x][y] == 2) {
			set_one(x, y, dir[i] * 2);
			set_one(x, y, dir[i] * 2 + 1);
		}
		else if (a[x][y] == 3) {
			if (dir[i] == 0) {
				set_one(x, y, 0);
				set_one(x, y, 2);
			}
			else if (dir[i] == 1) {
				set_one(x, y, 0);
				set_one(x, y, 3);
			}
			else if (dir[i] == 2) {
				set_one(x, y, 1);
				set_one(x, y, 2);
			}
			else if (dir[i] == 3) {
				set_one(x, y, 1);
				set_one(x, y, 3);
			}
		}
		else if (a[x][y] == 4) {
			for (int j = 0; j < 4; j++) {
				if (j == dir[i]) continue;
				set_one(x, y, j);
			}
		}
		else if (a[x][y] == 5) {
			for (int i = 0; i < 4; i++) {
				set_one(x, y, i);
			}
		}
	}
}
void go(int index) {
	if (index == cctv.size()) {
		set_cctv_area();
		int cnt = count_blind_spot();
		ans = min(ans, cnt);
		return;
	}
	if (a[cctv[index].first][cctv[index].second] == 2) {
		for (int i = 0; i < 2; i++) {
			dir.push_back(i);
			go(index + 1);
			dir.pop_back();
		}
		return;
	}
	else if (a[cctv[index].first][cctv[index].second] == 5) {	// 5번 cctv는 for문에서 4번까지 안돌게.
		dir.push_back(4);	// 이거 다시 생각해봐.
		go(index + 1);
		dir.pop_back();
		return;
	}
	for (int i = 0; i < 4; i++) {
		dir.push_back(i);
		go(index + 1);
		dir.pop_back();
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];

			if (a[i][j] != 0 && a[i][j] != 6) {
				cctv.push_back(make_pair(i, j));
			}
		}
	}
	go(0);
	cout << ans;

	return 0;
}
/*
카메라를 넘어가는 경우를 생각 못했음.
a[nx][ny] == 0  ->  a[nx][ny] != 6
로 해결.
반례찾는 연습하자. 사실 질문 검색에서 남이 올려준 반례로 해결함.
*/