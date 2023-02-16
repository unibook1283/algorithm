#include <iostream>
#include <vector>
using namespace std;
int go(vector<int> v, int bottom) {
	int mini = v[0], min_index = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] < mini) {
			mini = v[i];
			min_index = i;
		}
	}
	int ret = 0;
	ret += mini - bottom;
	if (min_index > 0) {
		vector<int> left(v.begin(), v.begin() + min_index);
		ret += go(left, mini);
	}
	if (min_index + 1 < v.size()) {
		vector<int> right(v.begin() + min_index + 1, v.end());
		ret += go(right, mini);
	}
	return ret;
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n), diff(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		diff[i] = a[i] - b[i];

	vector<int> v;
	v.push_back(abs(diff[0]));
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (diff[i] * diff[i - 1] < 0) {
			ans += go(v, 0);
			v.clear();
		}
		v.push_back(abs(diff[i]));
	}
	ans += go(v, 0);
	cout << ans << '\n';

	return 0;
}