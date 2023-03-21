#include <iostream>
#include <cstring>
using namespace std;
long long cache[51][51][51][51];
int da[] = { 1,0,0,1,1,0,1 };
int db[] = { 0,1,0,1,0,1,1 };
int dc[] = { 0,0,1,0,1,1,1 };
long long go(int S, int a, int b, int c) {
	if (S == 0) {
		if (a == 0 && b == 0 && c == 0) {
			return 1;
		}
		return 0;
	}
	long long& ret = cache[S][a][b][c];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 7; i++) {
		ret += go(S - 1, a - da[i], b - db[i], c - dc[i]);
	}
	ret %= 1000000007;
	return ret;
}
int main() {
	int S, a, b, c;
	cin >> S >> a >> b >> c;
	memset(cache, -1, sizeof(cache));

	cout << go(S, a, b, c) << '\n';

	return 0;
}