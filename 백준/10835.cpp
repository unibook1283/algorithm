#include <iostream>
#include <cstring>
using namespace std;
int a[2001], b[2001];
int cache[2001][2001];
int n;
int go(int a_index, int b_index) {
	if (a_index == n || b_index == n) return 0;
	int& ret = cache[a_index][b_index];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, go(a_index + 1, b_index));
	ret = max(ret, go(a_index + 1, b_index + 1));
	if (a[a_index] > b[b_index])
		ret = max(ret, b[b_index] + go(a_index, b_index + 1));
	return ret;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	memset(cache, -1, sizeof(cache));
	cout << go(0, 0) << '\n';

	return 0;
}