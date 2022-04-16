#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int num_cnt[10] = { 0, };
	while (n) {
		int r = n % 10;
		num_cnt[r]++;
		n /= 10;
	}
	int six_nine = (num_cnt[6] + num_cnt[9] + 1) / 2;
	num_cnt[6] = six_nine;
	num_cnt[9] = six_nine;
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans = max(ans, num_cnt[i]);
	}
	cout << ans << '\n';

	return 0;
}