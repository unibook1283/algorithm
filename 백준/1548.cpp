#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
vector<int> v;
int cache[51][51];
int go(int start, int end) {
	if (start + 1 >= end) return end - start + 1;
	if (v[start] + v[start + 1] > v[end]) return end - start + 1;
	int& ret = cache[start][end];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, go(start + 1, end));
	ret = max(ret, go(start, end - 1));
	return ret;
}
int main() {
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	memset(cache, -1, sizeof(cache));
	cout << go(0, n - 1) << '\n';

	return 0;
}