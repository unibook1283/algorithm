#include <iostream>
#include <queue>
using namespace std;
int main() {
	int n, h, t;
	cin >> n >> h >> t;

	priority_queue<int> pq;
	while (n--) {
		int x;
		cin >> x;
		pq.push(x);
	}

	int cnt = 0;
	while (!pq.empty() && cnt < t) {
		int x = pq.top();
		if (x == 1) break;
		if (x < h) {
			cout << "YES\n";
			cout << cnt << '\n';
			return 0;
		}
		pq.pop();
		pq.push(x / 2);
		cnt++;
	}
	if (pq.top() < h) {
		cout << "YES\n";
		cout << cnt << '\n';
		return 0;
	}
	cout << "NO\n";
	cout << pq.top() << '\n';

	return 0;
}