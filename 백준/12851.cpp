#include <iostream>
#include <queue>
using namespace std;
const int MAX = 100001;
int n, k;
bool check[MAX];
int ans = -1;
int cnt = 0;
void bfs() {
	check[n] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	while (!q.empty()) {
		int x = q.front().first;
		int d = q.front().second;
		q.pop();
		check[x] = true;
		if (ans != -1 && d > ans) return;
		if (x == k) {
			ans = d;
			cnt++;
		}
		if (x - 1 >= 0 && !check[x - 1])
			q.push(make_pair(x - 1, d + 1));
		if (x + 1 < MAX && !check[x + 1])
			q.push(make_pair(x + 1, d + 1));
		if (2 * x < MAX && !check[2 * x])
			q.push(make_pair(2 * x, d + 1));
	}
}
int main() {
	cin >> n >> k;
	bfs();
	cout << ans << '\n';
	cout << cnt << '\n';
	return 0;
}