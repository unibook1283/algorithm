#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string s, t;
	cin >> s >> t;

	while (s.length() <= t.length()) {
		if (s == t) {
			cout << 1 << '\n';
			return 0;
		}
		char last_ch = t[t.length() - 1];
		t.pop_back();
		if (last_ch == 'B') {
			reverse(t.begin(), t.end());
		}
	}
	cout << 0 << '\n';

	return 0;
}