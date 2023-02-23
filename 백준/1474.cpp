#include <iostream>
#include <vector>
using namespace std;
void add_underscores(string* s, int count) {
	for (int i = 0; i < count; i++)
		*s += '_';
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<string> v(n);
	int len_sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		len_sum += v[i].length();
	}
	int underscore_count = m - len_sum;
	int small = underscore_count / (n - 1);
	int small_count = n - 1 - underscore_count % (n - 1);
	int big_count = n - 1 - small_count;

	string ans = v[0];
	for (int i = 1; i < n; i++) {
		if (v[i][0] < '_') {
			if (small_count > 0) {
				small_count--;
				add_underscores(&ans, small);
			}
			else {
				big_count--;
				add_underscores(&ans, small + 1);
			}
		}
		else {
			if (big_count > 0) {
				big_count--;
				add_underscores(&ans, small + 1);
			}
			else {
				small_count--;
				add_underscores(&ans, small);
			}
		}
		ans += v[i];
	}
	cout << ans << '\n';

	return 0;
}