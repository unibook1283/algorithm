#include <iostream>
#include <queue>
using namespace std;
int main() {
	int n;
	cin >> n;
	priority_queue<pair<int, int>> pq;
	while (n--) {
		int t, s;
		cin >> t >> s;
		pq.push({ s,t });
	}

	int start_time = 987654321;
	while (!pq.empty()) {
		int t = pq.top().second;
		int s = pq.top().first;
		pq.pop();
		start_time = min(start_time, s) - t;
		if (start_time < 0) {
			cout << "-1\n";
			return 0;
		}
	}
	cout << start_time << '\n';

	return 0;
}