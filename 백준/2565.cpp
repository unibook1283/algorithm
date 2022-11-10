#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<pair<int, int>> v;
int cache[101][501];
int n;
int go(int index, int highest_b) {
	if (index == n) return 0;
	int& ret = cache[index][highest_b];
	if (ret != -1) return ret;
	ret = 987654321;
	ret = min(ret, 1 + go(index + 1, highest_b));
	if (v[index].second > highest_b)
		ret = min(ret, go(index + 1, max(highest_b, v[index].second)));
	return ret;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int from, to;
		cin >> from >> to;
		v.push_back(make_pair(from, to));
	}
	sort(v.begin(), v.end());
	memset(cache, -1, sizeof(cache));
	cout << go(0, 0) << '\n';

	return 0;
}