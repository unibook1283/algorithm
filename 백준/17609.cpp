#include <iostream>
using namespace std;
string s;
int go(int left, int right, int erase) {
	if (left >= right) return erase;
	int ret = 2;
	if (s[left] == s[right])
		ret = min(ret, go(left + 1, right - 1, erase));
	if (erase == 0) {
		ret = min(ret, go(left + 1, right, erase + 1));
		ret = min(ret, go(left, right - 1, erase + 1));
	}
	return ret;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		cout << go(0, s.size() - 1, false) << '\n';
	}

	return 0;
}