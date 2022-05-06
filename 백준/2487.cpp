#include <iostream>
#include <vector>
using namespace std;
int cal_gcd(int x, int y) {
	if (x == 0) return y;
	return cal_gcd(y % x, x);
}
int main() {
	int n;
	cin >> n;
	vector<int> v(n + 1), check(n + 1), cycles;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 1;
		if (check[i] == false) {
			check[i] = true;
			int index = v[i];
			while (index != i) {
				check[index] = true;
				index = v[index];
				cnt++;
			}
			if (cnt != 1) cycles.push_back(cnt);
		}
	}
	long long ans = 1;
	for (int i = 0; i < cycles.size(); i++) {
		int gcd = cal_gcd(ans, cycles[i]);
		ans = ans * cycles[i] / gcd;
	}
	cout << ans << '\n';


	return 0;
}