#include <iostream>
#include <algorithm>
using namespace std;
string go(string s) {
	int len = s.length();
	string ans = "";
	for (int i = 1; i < len - 1; i++) {
		for (int j = 1; i + j < len; j++) {
			string a, b, c;
			a = s.substr(0, i);
			b = s.substr(i, j);
			c = s.substr(i + j, len - i - j);
			reverse(a.begin(), a.end());
			reverse(b.begin(), b.end());
			reverse(c.begin(), c.end());
			string res = a + b + c;
			if (ans == "" || ans > res) ans = res;
		}
	}
	return ans;
}
int main() {
	string s;
	cin >> s;
	cout << go(s) << '\n';

	return 0;
}