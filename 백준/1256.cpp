#include <iostream>
#include <cstring>
using namespace std;
int skip;
string ans = "";
int cache[201][101];
const int M = 1000000000 + 100;
int bino(int n, int m) {
	if (n == m || m == 0) return 1;
	int& ret = cache[n][m];
	if (ret != -1) return ret;
	return ret = min(M, bino(n - 1, m - 1) + bino(n - 1, m));
}
void go(int n, int m, string s) {
	if (skip < 0) return;
	if (n == 0 && m == 0) {
		if (skip-- == 0) ans = s;
		return;
	}
	if (bino(n + m, n) <= skip) {
		skip -= bino(n + m, n);
		return;
	}
	if (n - 1 >= 0)
		go(n - 1, m, s + 'a');
	if (m - 1 >= 0)
		go(n, m - 1, s + 'z');
}
int main() {
	int n, m;
	cin >> n >> m >> skip;
	skip--;

	memset(cache, -1, sizeof(cache));
	go(n, m, "");
	if (ans == "") cout << "-1\n";
	else cout << ans << '\n';

	return 0;
}