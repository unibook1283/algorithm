#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100001;
int main() {
	int n, s;
	cin >> n >> s;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int left = 0, right = 0, sum = 0;
	int min_len = MAX;
	while (left <= right) {
		if (sum >= s) {
			min_len = min(min_len, right - left);
			sum -= v[left++];
		}
		else {
			if (right == n) break;
			sum += v[right++];
		}
	}
	if (min_len == MAX) cout << "0\n";
	else cout << min_len << '\n';

	return 0;
}