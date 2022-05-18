#include <iostream>
#include <vector>
using namespace std;
bool a[10];
int n, m;
int ans = 0;
bool is_possible(vector<int>& v) {
	for (int i = 0; i < 10; i++) {
		if (a[i]) {
			bool found = false;
			for (int j = 0; j < n; j++) {
				if (v[j] == i) {
					found = true;
				}
			}
			if (!found) return false;
		}
	}
	return true;
}
void go(int index, vector<int>& v) {
	if (index == n) {
		if (is_possible(v)) {
			ans++;
		}
		return;
	}
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		go(index + 1, v);
		v.pop_back();
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		a[x] = true;
	}

	vector<int> v;
	go(0, v);

	cout << ans << '\n';

	return 0;
}
