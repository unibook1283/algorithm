#include <iostream>
#include <cstring>
using namespace std;
int n, k;
int a[101][10001];
int cache[101][10001];
int go(int index, int prevRibbonIndex) {
	if (index == n) {
		return 0;
	}
	int& ret = cache[index][prevRibbonIndex == -1 ? 0 : prevRibbonIndex];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < k; i++) {
		if (i == prevRibbonIndex)
			continue;
		ret = max(ret, a[index][i] + go(index + 1, i));	
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			cin >> a[i][j];

	memset(cache, -1, sizeof(cache));
	cout << go(0, -1) << '\n';

	return 0;
}