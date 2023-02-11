#include <iostream>
using namespace std;
int n, k, d;
struct Rule {
	int a, b, c;
};
Rule rules[10001];
long long count_acorn_below_box_number(int box_number) {
	long long ret = 0;
	for (int i = 0; i < k; i++) {
		Rule rule = rules[i];
		if (box_number >= rule.a)
			ret += (min(box_number, rule.b) - rule.a) / rule.c + 1;
	}
	return ret;
}
int main() {
	cin >> n >> k >> d;
	for (int i = 0; i < k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		rules[i].a = a;
		rules[i].b = b;
		rules[i].c = c;
	}
	int left = 0, right = n;
	int ans = 987654321;
	while (left <= right) {
		int mid = (left + right) / 2;
		long long cnt = count_acorn_below_box_number(mid);
		if (d <= cnt) {
			right = mid - 1;
			ans = min(ans, mid);
		}
		else {
			left = mid + 1;
		}
	}
	cout << ans << '\n';

	return 0;
}