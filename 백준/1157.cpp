#include <iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	int a[26] = { 0, };
	for (char c : s) {
		if (c >= 'a') {
			c -= 'a';
		}
		else {
			c -= 'A';
		}
		a[c]++;
	}
	int max_index;
	int maxi = 0;
	for (int i = 0; i < 26; i++) {
		if (maxi < a[i]) {
			maxi = a[i];
			max_index = i;
		}
	}
	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (maxi == a[i]) cnt++;
	}
	if (cnt > 1) cout << "?";
	else cout << (char)('A' + max_index) << '\n';
	return 0;
}