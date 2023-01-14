#include <iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	int len = s.length();
	int zero = 0, one = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == '0') zero++;
		else one++;
	}

	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1') {
			s.erase(i, 1);
			i--;
			cnt++;
		}
		if (cnt == one / 2) break;
	}
	cnt = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == '0') {
			s.erase(i, 1);
			i++;
			cnt++;
		}
		if (cnt == zero / 2) break;
	}
	cout << s << '\n';
}