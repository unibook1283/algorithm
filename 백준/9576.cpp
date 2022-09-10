#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<bool> check(n + 1);
		priority_queue<pair<int, int>> pq;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			pq.push(make_pair(-b, -a));
		}
		int ans = 0;
		while (!pq.empty()) {
			int a = -pq.top().second;
			int b = -pq.top().first;
			pq.pop();
			for (int i = a; i <= b; i++) {
				if (!check[i]) {
					check[i] = true;
					ans++;
					break;
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}