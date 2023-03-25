#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<>());

	priority_queue<int> pq;
	for (int i = 0; i < min(n, m); i++) {
		pq.push(-v[i]);
	}

	for (int i = m; i < n; i++) {
		int x = -pq.top();
		pq.pop();
		pq.push(-(x + v[i]));
	}

	while (pq.size() != 1) {
		pq.pop();
	}

	cout << -pq.top() << '\n';

	return 0;
}