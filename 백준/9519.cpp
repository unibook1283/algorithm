#include <iostream>
#include <algorithm>
using namespace std;
void next(string& s) {
	string a, b;
	for (int i = 0; i < s.length(); i++) {
		if (i % 2 == 0) {
			a += s[i];
		}
		else {
			b += s[i];
		}
	}
	reverse(b.begin(), b.end());
	s = a + b;
}
int main() {
	int x;
	string s;
	cin >> x >> s;

	string temp = s;
	int mod = 0;
	while (1) {
		mod++;
		next(temp);
		if (temp == s) break;
	}

	x %= mod;

	while (x--) {
		next(s);
	}
	
	cout << s << '\n';

	return 0;
}