#include <iostream>
#include <algorithm>
using namespace std;
string s, t;
string reverseString(string s) {
	reverse(s.begin(), s.end());
	return s;
}
bool go(string t) {
	if (s.length() == t.length()) {
		if (s == t) return true;
		return false;
	}
	bool ret = false;
	if (t.back() == 'A') ret = go(t.substr(0, t.length() - 1));
	if (t.front() == 'B') ret = ret || go(reverseString(t).substr(0, t.length() - 1));
	return ret;
}
int main() {
	cin >> s >> t;
	cout << go(t) << '\n';

	return 0;
}