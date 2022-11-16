#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int a[301][21];
int cache[301][21];
int n, m;
int go(int company, int amount) {	// (기업 index, 남은 투자 금액)
	if (company == m) {
		return 0;
	}
	int& ret = cache[company][amount];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i <= n; i++) {
		if (amount >= i) {
			ret = max(ret, a[company][i] + go(company + 1, amount - i));
		}
		else break;
	}
	return ret;
}
void reconstruct(vector<int>& v, int index, int prev_max) {
	if (index == -1) return;
	int maxi = 0, maxi_index = 0;
	for (int i = 0; i <= n; i++) {
		if (maxi < cache[i][index]) {
			maxi = cache[i][index];
			maxi_index = index;
		}
		if (prev_max == cache[i][index] + a[i][index]) {
			v.push_back(i);
			reconstruct(v, index - 1, cache[i][index]);
			return;
		}
	}
	cout << "maxi : " << maxi << ", maxi_index : " << maxi_index << '\n';
	v.push_back(maxi_index);
	reconstruct(v, index - 1, maxi);
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int amount;
		cin >> amount;
		for (int j = 0; j < m; j++)
			cin >> a[j][amount];
	}
	memset(cache, -1, sizeof(cache));
	cout << go(0, n) << '\n';
	
	vector<int> v;
	reconstruct(v, m - 1, 0);
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << '\n';

	return 0;
}