#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	string s[2];
	for (int i = 0; i < 2; i++) {
		cin >> s[i];
	}

	if (s[0][0] != s[1][0] || s[0][n - 1] != s[1][n - 1]) {
		cout << "NO" << '\n';
		return 0;
	}
	
	string mo[2], ja[2];
	for (int i = 0; i < 2; i++) {
		for (char ch : s[i]) {
			if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
				mo[i].push_back(ch);
			}
			else {
				ja[i].push_back(ch);
			}
		}
	}
	if (ja[0] != ja[1]) {
		cout << "NO" << '\n';
		return 0;
	}
	for (int i = 0; i < 2; i++) {
		sort(mo[i].begin(), mo[i].end());
	}
	if (mo[0] != mo[1]) {
		cout << "NO" << '\n';
		return 0;
	}
	cout << "YES" << '\n';

	return 0;
}