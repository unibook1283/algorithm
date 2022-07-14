#include <iostream>
#include <vector>
using namespace std;
vector<int> problems[11];
int n, m;
bool all_solved(vector<bool>& v) {
	for (int i = 1; i <= n; i++) {
		if (!v[i]) return false;
	}
	return true;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int cnt;
		cin >> cnt;
		while (cnt--) {
			int p;
			cin >> p;
			problems[i].push_back(p);
		}
	}
	int ans = 987654321;
	for (int i = 0; i < (1 << m); i++) {
		vector<bool> v(n + 1);
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			if (i & (1 << j)) {
				cnt++;
				for (int k = 0; k < problems[j].size(); k++) {
					v[problems[j][k]] = true;
				}
			}
		}
		if (all_solved(v)) {
			ans = min(ans, cnt);
		}
	}
	if (ans == 987654321) cout << "-1\n";
	else cout << ans << '\n';

	return 0;
}