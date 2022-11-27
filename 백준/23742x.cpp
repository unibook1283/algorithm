#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<>());

	if (v[0] < 0) {
		long long sum = 0;
		for (int i = 0; i < n; i++) sum += v[i];
		cout << sum << '\n';
		return 0;
	}

	long long sum = 0;
	long long mul_of_sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
		long long temp = sum * (i + 1);
		if (temp >= mul_of_sum) {
			mul_of_sum = temp;
		}
		else {
			for (int j = i; j < n; j++) {
				mul_of_sum += v[j];
			}
			cout << mul_of_sum << '\n';
			return 0;
		}
	}
	cout << mul_of_sum << '\n';

	return 0;
}