#include <iostream>
#include <stack>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	stack<pair<int, int>> s;	// (index, height)
	for (int i = 1; i <= n; i++) {
		int height;
		cin >> height;
		while (!s.empty()) {
			if (s.top().second < height) s.pop();
			else {
				cout << s.top().first << ' ';
				break;
			}
		}
		if (s.empty()) {
			cout << "0 ";
		}
		s.push(make_pair(i, height));
	}
	cout << '\n';

	return 0;
}