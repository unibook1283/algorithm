#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> get_psum(vector<int> v) {
	vector<int> psum;
	for (int i = 0; i < v.size(); i++) {
		int sum = v[i];
		psum.push_back(sum);
		for (int j = i + 1; j < v.size(); j++) {
			sum += v[j];
			psum.push_back(sum);
		}
	}
	return psum;
}
int main() {
	int t, n, m;
	cin >> t >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; i++)
		cin >> b[i];

	vector<int> psum_a = get_psum(a);
	vector<int> psum_b = get_psum(b);
	sort(psum_b.begin(), psum_b.end());

	long long ans = 0;
	for (int i = 0; i < psum_a.size(); i++) {
		auto start = lower_bound(psum_b.begin(), psum_b.end(), t - psum_a[i]);
		auto end = upper_bound(psum_b.begin(), psum_b.end(), t - psum_a[i]);
		ans += end - start;
	}
	cout << ans << '\n';

	return 0;
}