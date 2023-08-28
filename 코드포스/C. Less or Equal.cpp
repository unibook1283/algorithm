#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int answer;
	if (k == 0) {
		if (v[0] == 1) answer = -1;
		else answer = 1;
	}
	else {
		answer = (k < n && v[k - 1] == v[k]) ? -1 : v[k - 1];
	}
	cout << answer << '\n';

	return 0;
}