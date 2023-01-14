#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n), sum(n);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v[i] = num == 1 ? -1 : 1;
		sum[i] = i == 0 ? v[i] : sum[i - 1] + v[i];
	}

	int mini = 0, maxi = 0;
	for (int i = 0; i < n; i++) {
		mini = min(mini, sum[i]);
		maxi = max(maxi, sum[i]);
	}
	cout << maxi - mini << '\n';

	return 0;
}