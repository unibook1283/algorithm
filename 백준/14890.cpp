#include <iostream>
#include <vector>
using namespace std;
int a[100][100];
int n, l;
bool test(int index, int dir) {	//dir: 0 -> 가로    1 -> 세로
	vector<int> v;
	for (int i = 0; i < n; i++) {
		if (dir == 0) {
			v.push_back(a[index][i]);
		}
		else {
			v.push_back(a[i][index]);
		}
	}
	int repeat = 1;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == v[i - 1]) {
			repeat++;
		}
		else if (v[i] - v[i - 1] == 1) {
			if (l > repeat) return false;
			repeat = 1;
		}
		else if (v[i] - v[i - 1] == -1) {
			if (i + l > n) return false;
			for (int j = 1; j < l; j++) {
				if (v[i] != v[i + j]) return false;
			}
			for (int j = l; j < l * 2; j++) {
				if (i + j < n) {
					if (v[i + j] > v[i]) return false;
				}
			}
			i += l - 1;
			repeat = 1;
		}
		else {
			// 여기까지 온 것은 높이 차이가 1보다 크다는 것.
			return false;
		}
	}
	return true;
}
int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			if (test(i, j)) {
				cout << i << ' ' << j << '\n';
				ans++;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}