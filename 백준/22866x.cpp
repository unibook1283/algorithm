#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int cal_cnt(vector<int> v, int x) {
	if (v[x] == 0) return 0;
	return 1 + cal_cnt(v, v[x]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	vector<int> left(n + 1), right(n + 1);
	stack<pair<int, int>> s;	// (index, height)
	for (int i = 1; i <= n; i++) {
		int cur = v[i];
		while (!s.empty() && s.top().second < cur) {
			left[s.top().first] = i;
			s.pop();
		}
		s.push(make_pair(i, cur));
	}
	
	while (!s.empty()) s.pop();

	for (int i = n; i >= 0; i--) {
		int cur = v[i];
		while (!s.empty() && s.top().second < cur) {
			right[s.top().first] = i;
			s.pop();
		}
		s.push(make_pair(i, cur));
	}

	for (int i = 1; i <= n; i++) {
		int left_cnt = cal_cnt(left, i);
		int right_cnt = cal_cnt(right, i);
		int total_cnt = left_cnt + right_cnt;
		if (total_cnt == 0) {
			cout << "0\n";
			continue;
		}
		int ans_cnt = (right[i] != 0 ? right[i] : left[i]);
		cout << total_cnt << ' ' << ans_cnt << '\n';
	}

	return 0;
}