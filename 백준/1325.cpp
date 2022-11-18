#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int> v[10001];
bool check[10001];
int cnt = 0;
void dfs(int x) {
	check[x] = true;
	for (int i = 0; i < v[x].size(); i++) {
		int nx = v[x][i];
		if (!check[nx]) {
			cnt++;
			dfs(nx);
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}

	vector<int> ans;
	int maxi = 0;
	for (int i = 1; i <= n; i++) {
		memset(check, false, sizeof(check));
		cnt = 0;
		dfs(i);
		if (cnt > maxi) {
			maxi = cnt;
			ans.clear();
			ans.push_back(i);
		}
		else if (cnt == maxi) {
			ans.push_back(i);
		}
	}

	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << '\n';

	return 0;
}