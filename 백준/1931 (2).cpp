#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		pq.push(make_pair(-b, -a));
	}
	int start = 0, ans = 0;
	while (!pq.empty()) {
		int a = -pq.top().second;
		int b = -pq.top().first;
		pq.pop();
		if (start <= a) {
			ans++;
			start = b;
		}
	}
	cout << ans << '\n';

	return 0;
}