#include <iostream>
#include <vector>
#include <algorithm>
int a[1000001];
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> v;
	v.push_back(a[0]);
	for (int i = 1; i < n; i++) {
		if (a[i] > v.back()) {
			v.push_back(a[i]);
		}
		else {
			int iter = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
			v[iter] = a[i];
		}
	}
	cout << v.size() << '\n';

	return 0;
}