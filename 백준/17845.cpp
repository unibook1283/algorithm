#include <iostream>
#include <cstring>
using namespace std;
int l[1000], t[1000];
int cache[1001][10001];
int n, k;
int go(int index, int time) {
	if (index == k) return 0;
	int &ret = cache[index][time];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, go(index + 1, time));
	if (time + t[index] <= n)
		ret = max(ret, l[index] + go(index + 1, time + t[index]));
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> l[i] >> t[i];
	}
	cout << go(0, 0) << '\n';

	return 0;
}