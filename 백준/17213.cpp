#include <iostream>
using namespace std;
int n, m;
int ans = 0;
void go(int cnt, int d) {
	if (cnt == m) {
		ans++;
		return;
	}
	for (int i = d; i < n; i++) {
		go(cnt + 1, i);
	}
}
int main() {
	cin >> n >> m;
	m -= n;
	go(0, 0);

	cout << ans << '\n';

	return 0;
}