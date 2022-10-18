#include <iostream>
using namespace std;
int a[250001];
int main() {
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}

	int maxi = 0;
	int maxi_cnt = 0;
	for (int i = 0; i <= n - x; i++) {
		int sum = a[i + x] - a[i];
		if (maxi == sum) maxi_cnt++;
		else if (maxi < sum) {
			maxi = sum;
			maxi_cnt = 1;
		}
	}
	if (maxi == 0) {
		cout << "SAD\n";
	}
	else {
		cout << maxi << '\n';
		cout << maxi_cnt << '\n';
	}

	return 0;
}