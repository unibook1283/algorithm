#include <iostream>
using namespace std;
string s;
int ans = 0;
void go(int index, int prev) {
	if (index == s.size()) {
		ans++;
		return;
	}
	if (s[index] == 'd') {
		for (int i = 0; i < 10; i++) {
			if (i == prev) continue;
			go(index + 1, i);
		}
	}
	else {
		for (int i = 97; i < 123; i++) {
			if (i == prev) continue;
			go(index + 1, i);
		}
	}
}
int main() {
	cin >> s;
	go(0, -1);

	cout << ans << '\n';

	return 0;
}