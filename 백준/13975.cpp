#include <iostream>
#include <queue>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		priority_queue<long long> pq;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			long long num;
			cin >> num;
			pq.push(-num);
		}

		long long ans = 0;
		while (!pq.empty()) {
			long long first = -pq.top();
			pq.pop();
			if (pq.empty()) {
				continue;
			}
			long long second = -pq.top();
			pq.pop();

			long long sum = first + second;
			ans += sum;
			pq.push(-sum);
		}
		cout << ans << '\n';
	}

	return 0;
}