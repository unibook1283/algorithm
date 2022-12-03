#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int cache[1001][10];
const int MOD = 1234567;
vector<vector<int>> v = {
	{7},
	{2,4},
	{1,3,5},
	{2,6},
	{1,5,7},
	{2,4,6,8},
	{3,5,9},
	{0,4,8},
	{5,7,9},
	{6,8}
};
int go(int index, int cur) {
	if (index == 0) return 1;
	int& ret = cache[index][cur];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < v[cur].size(); i++) {
		ret = (ret + go(index - 1, v[cur][i])) % MOD;
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		n--;
		int cnt = 0;
		for (int i = 0; i < 10; i++) {
			cnt = (cnt + go(n, i)) % MOD;
		}
		cout << cnt << '\n';
	}

	return 0;
}