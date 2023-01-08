#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<pair<int, pair<int, int>>> v;
	int left = 0, right = n - 1;
	while (left < right) {
		int sum = a[left] + a[right];
		v.push_back(make_pair(abs(sum), make_pair(a[left], a[right])));
		if (sum > 0) {
			right--;
		}
		else {
			left++;
		}
	}
	sort(v.begin(), v.end());
	cout << v.front().second.first << ' ' << v.front().second.second << '\n';

	return 0;
}