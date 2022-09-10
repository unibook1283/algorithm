#include <iostream>
#include <queue>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;

	priority_queue<long long> pq;
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		pq.push(-num);
	}

	while (m--) {
		long long a = -pq.top(); pq.pop();
		long long b = -pq.top(); pq.pop();
		long long sum = a + b;
		pq.push(-sum);
		pq.push(-sum);
	}
	long long ans = 0;
	while (!pq.empty()) {
		ans += -pq.top();
		pq.pop();
	}
	cout << ans << '\n';

	return 0;
}