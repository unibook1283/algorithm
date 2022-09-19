#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}
	for (int i = 0; i < m; i++) {
		int wi;
		cin >> wi;
		int ci = pq.top();
		pq.pop();
		if (ci >= wi) {
			pq.push(ci - wi);
		}
		else {
			cout << 0 << '\n';
			return 0;
		}
	}
	cout << 1 << '\n';

	return 0;
}