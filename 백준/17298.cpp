#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n), ans(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	stack<pair<int, int>> s;	// (ai, index)
	for (int i = 0; i < n; i++) {
		while (!s.empty() && s.top().first < a[i]) {
			ans[s.top().second] = a[i];
			s.pop();
		}
		s.push(make_pair(a[i], i));
	}
	while (!s.empty()) {
		ans[s.top().second] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << '\n';

	return 0;
}