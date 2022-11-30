#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, m, k, y_size;
	cin >> n >> m >> k >> y_size;

	int Mx = 0;
	vector<int> ys;
	for (int i = 0; i < y_size; i++) {
		int x, y;
		cin >> x >> y;
		y--;
		Mx = max(Mx, x);
		ys.push_back(y);
	}
	sort(ys.begin(), ys.end());

	int cnt = 0;
	int size = Mx;
	while (1) {
		int last_covered_y = -1;
		for (int i = 0; i < y_size; i++) {
			if (last_covered_y <= ys[i]) {
				last_covered_y = ys[i] + size;
				cnt++;
			}
		}
		if (cnt <= k) break;
		cnt = 0;
		size++;
	}
	cout << size << '\n';

	return 0;
}