#include <iostream>
#include <stack>
using namespace std;
int main() {
	stack<int> s;
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		while (!s.empty() && s.top() > y) {
			s.pop();
			ans++;
		}
		if (s.empty() || s.top() < y)
			s.push(y);
	}
	while (!s.empty() && s.top() != 0) {
		s.pop();
		ans++;
	}
	cout << ans << '\n';

	return 0;
}