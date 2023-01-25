#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;
	stack<int> s;
	int erase_cnt = 0;
	for (char ch : str) {
		while (!s.empty() && s.top() < ch && erase_cnt < k) {
			s.pop();
			erase_cnt++;
		}
		s.push(ch);
	}
	while (!s.empty() && erase_cnt < k) {
		s.pop();
		erase_cnt++;
	}

	string ans = "";
	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';

	return 0;
}