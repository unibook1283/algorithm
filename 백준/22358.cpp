#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<pair<long long, long long>> v[100001];
long long cache[100001][11];
int n, m, k, s, e;
long long dfs(int cur, int lift) {
	if (cur == e && lift == k) return 0;
	long long& ret = cache[cur][lift];
	if (ret != -1) return ret;
	ret = -1e16;
	for (int i = 0; i < v[cur].size(); i++) {
		long long next = v[cur][i].first;
		long long cost = v[cur][i].second;
		if (cur < next)
			ret = max(ret, cost + dfs(next, lift));
		else if (lift < k)
			ret = max(ret, dfs(next, lift + 1));
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> n >> m >> k >> s >> e;
	for (int i = 0; i < m; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	long long res = dfs(s, 0);
	if (res < 0) cout << "-1\n";
	else cout << res << '\n';

	return 0;
}