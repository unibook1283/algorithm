#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int a[201][201];
bool d[201];
const int INF = 987654321;
int n, m;
void bfs(int x) {
	d[x] = true;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 0; i < n; i++) {
			if (a[x][i] && !d[i]) {
				d[i] = true;
				q.push(i);
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	vector<int> plan(m);
	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;
		plan[i] = p - 1;
	}

	sort(plan.begin(), plan.end());
	plan.erase(unique(plan.begin(), plan.end()), plan.end());

	bfs(plan[0]);
	for (int i = 0; i < plan.size(); i++) {
		if (d[plan[i]] == false) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";

	return 0;
}