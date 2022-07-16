#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool check[1001];
struct cmp {
	bool operator() (pair<int, int>& u, pair<int, int>& v) {
		if (u.second == v.second) {
			return u.first < v.first;
		}
		return u.second < v.second;
	}
};
int main() {
	int n;
	cin >> n;
	priority_queue <pair<int, int>, vector<pair<int, int>>, cmp> pq;
	int maxd = 0;
	for (int i = 0; i < n; i++) {
		int d, w;
		cin >> d >> w;
		pq.push(make_pair(d, w));
	}
	int ans = 0;
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		int day = p.first;
		int w = p.second;
		for (int i = day; i >= 1; i--) {
			if (!check[i]) {
				check[i] = true;
				ans += w;
				break;
			}
		}
	}
	cout << ans << '\n';


	return 0;
}