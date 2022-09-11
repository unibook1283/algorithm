#include <iostream>
#include <queue>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	priority_queue<int> pq;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	int price = 0;
	int profit = 0;
	for (int i = 1; i <= n; i++) {
		if (pq.empty()) continue;
		int x = pq.top();
		pq.pop();
		if (profit < i * x) {
			profit = i * x;
			price = x;
		}
	}
	cout << price << ' ' << profit << '\n';

	return 0;
}