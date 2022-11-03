#include <iostream>
#include <cstring>
using namespace std;
int graph[50][50];
double percent[50];
double cache[51][101];
int n, d, p, q;
double dfs(int cur, int day) {
	if (day == d) return cur == q ? 1.0 : 0.0;
	double& ret = cache[cur][day];
	if (ret != -1.0) return ret;
	ret = 0.0;
	for (int next = 0; next < n; next++) {
		if (graph[cur][next]) {
			ret += dfs(next, day + 1) * percent[cur];
		}
	}
	return ret;
}
void init() {
	for (int i = 0; i < 51; i++)
		for (int j = 0; j < 101; j++)
			cache[i][j] = -1.0;
}
int main() {
	int c;
	cin >> c;
	while (c--) {
		cin >> n >> d >> p;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				cin >> graph[i][j];
				if (graph[i][j]) cnt++;
			}
			percent[i] = (double)1 / cnt;
		}
		int t;
		cin >> t;
		while (t--) {
			init();
			cin >> q;
			cout.precision(8);
			cout << dfs(p, 0) << ' ';
		}
		cout << '\n';
	}

	return 0;
}