#include <iostream>
#include <vector>
using namespace std;
bool cover_all(int n, vector<int> lamps, int height) {
	int end = 0;
	for (int x : lamps) {
		if (x - height > end) return false;
		end = x + height;
	}
	return end >= n;
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> lamps(m);
	for (int i = 0; i < m; i++) {
		cin >> lamps[i];
	}

	int answer = 100001;
	int left = 1, right = 100001;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (cover_all(n, lamps, mid)) {
			answer = min(answer, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << answer << '\n';

	return 0;
}