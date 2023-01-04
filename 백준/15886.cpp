#include <iostream>
using namespace std;
int main() {
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == 'E' && s[i + 1] == 'W') ans++;
	}
	cout << ans << '\n';

	return 0;
}