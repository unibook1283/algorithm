#include <iostream>
#include <stack>
using namespace std;
int main() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		stack<char> s;
		for (char ch : str) {
			if (!s.empty()) {
				if (ch == s.top()) {
					s.pop();
				}
				else {
					s.push(ch);
				}
			}
			else s.push(ch);
		}
		if (s.empty()) ans++;
	}
	cout << ans << '\n';

	return 0;
}