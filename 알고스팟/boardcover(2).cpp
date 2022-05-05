#include <iostream>
#include <vector>
using namespace std;
int h, w;
int l[4][3][2] = {
	{{0, 0}, {1, 0}, {1, -1}},
	{{0, 0}, {1, 0}, {1, 1}},
	{{0, 0}, {1, 0}, {0, 1}},
	{{0, 0}, {0, 1}, {1, 1}}
};
void set(char a[20][20], vector<pair<int, int>>& set_point, int set_black) {
	for (int i = 0; i < 3; i++) {
		int x = set_point[i].first;
		int y = set_point[i].second;
		if (set_black)
			a[x][y] = '#';
		else
			a[x][y] = '.';
	}
}
int go(char a[20][20]) {
	int x = -1, y;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '.') {
				x = i;
				y = j;
				break;
			}
		}
		if (x != -1) break;	// 이거 좋다. 나는 if (bool found) 이렇게 했었는데
	}
	if (x == -1) return 1;
	// 완성된 경우는 위에서 return 1 되는데, 채울 수 있는건 다 채웠는데
	// 완성 안 된 경우는 어떻게 찾을 것인가.
	// 아 그냥 ret=0이 return 되는구나 마지막에.

	int ret = 0;
	for (int k = 0; k < 4; k++) {
		bool possible = true;
		vector<pair<int, int>> set_point;
		for (int m = 0; m < 3; m++) {
			int nx = x + l[k][m][0];
			int ny = y + l[k][m][1];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w || a[nx][ny] == '#') {
				possible = false;
				break;
			}
			set_point.push_back(make_pair(nx, ny));
		}
		if (possible) {
			set(a, set_point, 1);
			ret += go(a);
			set(a, set_point, 0);
		}
	}
	return ret;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> h >> w;
		char a[20][20];
		int white_cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> a[i][j];
				if (a[i][j] == '.') white_cnt++;
			}
		}
		if (white_cnt % 3 != 0) {
			cout << 0 << '\n';
			continue;
		}
		cout << go(a) << '\n';
	}

	return 0;
}