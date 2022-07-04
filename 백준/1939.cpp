#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
vector<pair<int, long long>> v[100001];	// (목적지, 중량제한)
bool check[100001];
int n, m, from, to;
bool bfs(long long weight) {
	memset(check, false, sizeof(check));
	check[from] = true;
	queue<int> q;
	q.push(from);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == to) return true;
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			long long limit = v[x][i].second;
			if (limit >= weight && !check[nx]) {
				check[nx] = true;
				q.push(nx);
			}
		}
	}
	return false;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	cin >> from >> to;

	long long left = 1, right = 1000000000, ans = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (bfs(mid)) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans << '\n';


	return 0;
}