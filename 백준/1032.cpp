#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	string s[50];
	string ans;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	ans = s[0];
	for (int i = 0; i < s[0].size(); i++) {
		for (int j = 1; j < n; j++) {
			if (s[j][i] != s[0][i]) {
				ans[i] = '?';
				break;
			}
		}
	}
	cout << ans << '\n';


	return 0;
}