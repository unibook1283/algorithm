#include <iostream>
#include <vector>
using namespace std;
int fishes_cnt(int x, int y, int height, int width, vector<pair<int,int>> fishes) {
	int cnt = 0;
	for (int i = 0; i < fishes.size(); i++) {
		int fx = fishes[i].first;
		int fy = fishes[i].second;
		if (x <= fx && fx <= x + height &&
			y <= fy && fy <= y + width) {
			cnt++;
		}
	}
	return cnt;
}
int main() {
	int n, l, m;
	cin >> n >> l >> m;
	vector<pair<int, int>> fishes;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		fishes.push_back(make_pair(x, y));
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			int x = min(fishes[i].first, fishes[j].first);
			int y = min(fishes[i].second, fishes[j].second);
			for (int width = 1; width < l / 2; width++) {
				int height = l / 2 - width;
				if (x + height > n) continue;
				if (y + width > n) break;
				int cnt = fishes_cnt(x, y, height, width, fishes);
				ans = max(ans, cnt);
			}
		}
	}
	cout << ans << '\n';

	return 0;
}