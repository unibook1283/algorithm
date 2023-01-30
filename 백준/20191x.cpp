#include <iostream>
using namespace std;
string s, t;
int ans = -1;
void go(int s_index, int t_index, int n) {
	if (s_index == s.size()) {
		ans = n;
		return;
	}
	int index = t.find(s[s_index], t_index);
	// 못찾은 경우
	if (index == -1) {
		if (t_index != 0)
			go(s_index, 0, n + 1);
		return;
	}
	// 찾은 경우
	go(s_index + 1, index + 1, n);
}
int main() {
	cin >> s >> t;
	go(0, 0, 1);
	cout << ans << '\n';

	return 0;
}