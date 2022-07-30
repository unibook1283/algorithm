#include <iostream>
using namespace std;
int b[100001];
int n;
const int INF = 987654321;
int go(int d, int b1) {
	int cnt = 0;
	for (int i = 2; i < n; i++) {
		int di = b[i] - b1;
		if (d - di == 1 || d - di == -1) {
			cnt++;
		}
		else if (d - di == 0) {}
		else return -1;
		b1 += d;
	}
	return cnt;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	int ans = INF;
	for (int i = -1; i <= 1; i++) {
		int b0 = b[0] + i;
		int res = 0;
		if (i != 0) res = 1;
		for (int j = -1; j <= 1; j++) {
			int b1 = b[1] + j;
			if (j != 0) res++;
			int ret = go(b1 - b0, b1);
			if (ret != -1) ans = min(ans, res + ret);
			if (j != 0) res--;
		}
	}
	if (ans == INF) cout << "-1\n";
	else cout << ans << '\n';

	return 0;
}