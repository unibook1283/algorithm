#include <iostream>
using namespace std;
int a[1 << 21];
int k;
int ans = 0;
int go(int index) {
	if (index * 2 > (1 << (k + 1)) - 1) { // leaf node
		ans += a[index];
		return a[index];
	}
	int left = go(index * 2);
	int right = go(index * 2 + 1);
	ans += a[index] + abs(left - right);
	return a[index] + max(left, right);
}
int main() {
	cin >> k;
	for (int i = 2; i < (1 << (k + 1)); i++) {
		cin >> a[i];
	}

	go(1);
	cout << ans << '\n';

	return 0;
}