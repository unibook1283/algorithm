#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
int a[1001];
bool ans[1001];
vector<int> v[1001];
set<int> s;
int n, m, y;
bool cache[1001][1001];
void go(int x, int cnt) {
	if (cnt == y) {
		s.insert(x);
		return;
	}
	bool& ret = cache[x][cnt];
	if (ret == true) return;
	for (int i = 0; i < v[x].size(); i++) {
		int nx = v[x][i];
		go(nx, cnt + 1);
	}
	ret = true;
}
int main() {
	int x;
	cin >> n >> m >> x >> y;
	for (int i = 0; i < m; i++) {
		int p, q;
		cin >> p >> q;
		v[p].push_back(q);
		v[q].push_back(p);
	}
	go(x, 0);

	if (s.empty()) cout << "-1\n";
	else {
		for (int ans : s) {
			cout << ans << ' ';
		}
		cout << '\n';
	}

	return 0;
}