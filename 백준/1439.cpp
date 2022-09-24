#include <iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	char prev = s[0];
	int cnt = 1;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] != prev) {
			cnt++;
			prev = s[i];
		}
	}
	cout << cnt / 2 << '\n';

	return 0;
}