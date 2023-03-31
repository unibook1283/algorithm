#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());

	long long answer = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			int toFind = -(v[i] + v[j]);
			auto lb = lower_bound(v.begin() + j + 1, v.end(), toFind);
			auto ub = upper_bound(v.begin() + j + 1, v.end(), toFind);
			answer += ub - lb;
		}
	}
	cout << answer << '\n';

	return 0;
}