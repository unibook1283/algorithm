#include <iostream>
#include <cstring>
#include <set>
using namespace std;
int a[101];
bool check[101];
set<int> ans;
int cycle_start;
bool dfs(int x) {
	if (check[x]) {
		cycle_start = x;
		return true;
	}
	check[x] = true;
	if (dfs(a[x])) {
		ans.insert(x);
		if (cycle_start == x) return false;
		return true;
	}
	return false;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cycle_start = 0;
		memset(check, false, sizeof(check));
		dfs(i);
	}

	cout << ans.size() << '\n';
	for (auto p : ans) {
		cout << p << '\n';
	}

	return 0;
}