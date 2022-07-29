#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<long long> d(n - 1), cost(n);
	for (int i = 0; i < n - 1; i++) {
		cin >> d[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}

	long long ans = 0;
	long long min_cost = 1000000000;
	for (int i = 0; i < n - 1; i++) {
		min_cost = min(min_cost, cost[i]);
		ans += d[i] * min_cost;
	}
	cout << ans << '\n';

	return 0;
}