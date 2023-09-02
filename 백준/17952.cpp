#include <iostream>
#include <stack>
using namespace std;
int main() {
	int n;
	cin >> n;

	int total_score = 0;
	stack<pair<int, int>> s;	// (a, t)
	for (int i = 0; i < n; i++) {
		int op;
		cin >> op;
		if (op == 1) {
			int a, t;
			cin >> a >> t;
			if (t == 1) total_score += a;
			else s.push({ a, t - 1 });
		}
		else {
			if (s.empty()) continue;
			int a = s.top().first;
			int& t = s.top().second;
			t--;
			if (t == 0) {
				s.pop();
				total_score += a;
			}
		}
	}
	cout << total_score << '\n';

	return 0;
}