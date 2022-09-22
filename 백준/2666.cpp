#include <iostream>
#include <vector>
using namespace std;
int ans = 987654321;
void go(int index, int sum, int left, int right, vector<int> v) {
	if (index == v.size()) {
		ans = min(ans, sum);
		return;
	}
	int cur = v[index];
	int left_dist = abs(cur - left);
	int right_dist = abs(cur - right);
	go(index + 1, sum + left_dist, cur, right, v);
	go(index + 1, sum + right_dist, left, cur, v);
}
int main() {
	int n;
	cin >> n;
	int left, right;
	cin >> left >> right;
	int m;
	cin >> m;
	vector<int> v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}
	go(0, 0, left, right, v);
	cout << ans << '\n';

	return 0;
}