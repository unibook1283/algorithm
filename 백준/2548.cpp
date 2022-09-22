#include <iostream>
using namespace std;
int a[20001];
int n;
int sum_of_dif(int x) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += abs(x - a[i]);
	}
	return sum;
}
int main() {
	cin >> n;
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		maxi = max(maxi, a[i]);
	}

	int mini = 987654321;
	int ans;
	for (int i = 1; i <= maxi; i++) {
		int sod = sum_of_dif(i);
		if (mini > sod) {
			mini = sod;
			ans = i;
		}
	}
	cout << ans << '\n';

	return 0;
}