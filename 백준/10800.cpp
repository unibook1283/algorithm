#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<pair<int,pair<int,int>>> v;
	for (int i = 0; i < n; i++) {
		int color, size;
		cin >> color >> size;
		v.push_back(make_pair(size, make_pair(color - 1, i)));
	}
	sort(v.begin(), v.end());
	int sum = 0;
	vector<int> ans(n);
	vector<int> c_sum(n);
	vector<int> s_sum(2001);
	for (int i = 0; i < n; i++) {
		int size = v[i].first;
		int color = v[i].second.first;
		int index = v[i].second.second;

		sum += size;
		c_sum[color] += size;
		s_sum[size] += size;
		ans[index] = sum - c_sum[color] - s_sum[size] + size;
		if (i != 0 && (v[i - 1].first == size && v[i - 1].second.first == color))
			ans[index] = ans[v[i - 1].second.second];
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << '\n';

	return 0;
}