#include <iostream>
#include <cstring>
using namespace std;
int cache[201][201];
string a, b, c;
int go(int a_index, int b_index) {
	if (a_index + b_index == c.length()) return 1;
	int c_index = a_index + b_index;
	int& ret = cache[a_index][b_index];
	if (ret != -1) return ret;
	ret = 0;
	if (a_index < a.length() && c[c_index] == a[a_index])
		ret = max(ret, go(a_index + 1, b_index));
	if (b_index < b.length() && c[c_index] == b[b_index])
		ret = max(ret, go(a_index, b_index + 1));
	return ret;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> a >> b >> c;
		cout << "Data set " << i << ": " << (go(0, 0) ? "yes" : "no") << '\n';
	}

	return 0;
}