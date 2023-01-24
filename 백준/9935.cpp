#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main() {
	string str, expl;
	cin >> str >> expl;
	stack<char> s1;
	for (char ch : str) {
		stack<char> s2;
		s1.push(ch);
		int index = expl.size() - 1;
		while (!s1.empty() && index >= 0) {
			int top1 = s1.top();
			if (top1 == expl[index--]) {
				s2.push(top1);
				s1.pop();
			}
			else {
				while (!s2.empty()) {
					s1.push(s2.top());
					s2.pop();
				}
				break;
			}
		}
		if (index != -1) {
			while (!s2.empty()) {
				s1.push(s2.top());
				s2.pop();
			}
		}
	}
	if (s1.empty()) {
		cout << "FRULA\n";
		return 0;
	}
	string ans = "";
	while (!s1.empty()) {
		ans += s1.top();
		s1.pop();
	}
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';

	return 0;
}