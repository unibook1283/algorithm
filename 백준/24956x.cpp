#include <iostream>
#include <cstring>
using namespace std;
int n;
string s;
long long cache[200001][4];
char whee[4] = { 'W','H','E','E' };
const long long MOD = 1'000'000'007;
long long go(int index, int whee_index) {
	if (index == n) {
		return 0;
	}
	long long& ret = cache[index][whee_index];
	if (ret != -1) return ret;
	ret = 0;
	int next_whee_index = min(whee_index + 1, 3);
	char next_whee = whee[next_whee_index];
	for (int i = index + 1; i < n; i++) {
		if (s[i] == next_whee) {
			ret = (ret + go(i, next_whee_index)) % MOD;
			if (next_whee_index == 3) ret = (ret + 1) % MOD;
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s;
	memset(cache, -1, sizeof(cache));
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'W') {
			ans += go(i, 0);
		}
	}
	cout << ans << '\n';

	return 0;
}