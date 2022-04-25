#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
int a[1000001];
int d[1000001];
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		d[i] = 1;
	}
	vector<int> v;
	v.push_back(a[0]);
	for (int i = 1; i < n; i++) {
		if (a[i] > v.back()) {
			v.push_back(a[i]);
			d[i] = v.size();
		}
		else {
			int iter = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
			v[iter] = a[i];
			d[i] = iter + 1;
		}
	}
	stack<int> s;
	int maxd = 0;
	int maxd_index = 0;
	for (int i = 0; i < n; i++) {
		if (maxd < d[i]) {
			maxd = d[i];
			maxd_index = i;
		}
	}

	s.push(a[maxd_index]);
	maxd--;
	while (maxd_index--) {
		if (d[maxd_index] == maxd) {
			s.push(a[maxd_index]);
			maxd--;
		}
	}

	cout << v.size() << '\n';

	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	cout << '\n';

	return 0;
}