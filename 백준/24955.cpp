#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int a[1001];
bool check[1001];
vector<int> v[1001];
long long res;
const long long MOD = 1000000007;
long long concat(long long a, long long b) {
	for (int i = b; i > 0; i /= 10) {
		a = (a * 10) % MOD;
	}
	a += b;
	a %= MOD;
	return a;
}
void dfs(int x, int dest, long long cur) {
	cur = concat(cur, a[x]);
	if (x == dest) {
		res = cur;
		return;
	}
	check[x] = true;
	for (int i = 0; i < v[x].size(); i++) {
		int nx = v[x][i];
		if (!check[nx])
			dfs(nx, dest, cur);
	}
	check[x] = false;
}
int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;
		from--; to--;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	for (int i = 0; i < q; i++) {
		memset(check, false, sizeof(check));
		int from, to;
		cin >> from >> to;
		from--; to--;
		dfs(from, to, 0);
		cout << res << '\n';
	}

	return 0;
}