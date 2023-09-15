#include <iostream>
#include <set>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	set<int> s;
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x == 1) s.insert(i);
	}
	int cur_pos = 1;
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int i;
			cin >> i;
			if (s.count(i))
				s.erase(i);
			else
				s.insert(i);
		}
		else if (op == 2) {
			int x;
			cin >> x;
			cur_pos = (cur_pos - 1 + x) % n + 1;
		}
		else {
			if (s.empty()) {
				cout << -1 << '\n';
				continue;
			}
			int res;
			auto iter = s.lower_bound(cur_pos);
			if (iter == s.end())
				res = *s.begin() + n - cur_pos;
			else
				res = *iter - cur_pos;
			cout << res << '\n';
		}
	}

	return 0;
}