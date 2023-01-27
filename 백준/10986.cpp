#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<long long> cnt(m);
	
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		sum += num;
		cnt[sum % m]++;
	}

	long long ans = 0;
	for (int i = 0; i < m; i++) {
		ans += cnt[i] * (cnt[i] - 1) / 2;
	}
	cout << cnt[0] + ans << '\n';

	return 0;
}