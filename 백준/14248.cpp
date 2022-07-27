#include <iostream>
#include <queue>
using namespace std;
int a[100001];
bool check[100001];
int n;
int ans = 0;
void bfs(int x) {
	check[x] = true;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		x = q.front();
		q.pop();
		ans++;
		int nx = x - a[x];
		if (nx >= 0 && !check[nx]) {
			check[nx] = true;
			q.push(nx);
		}
		nx = x + a[x];
		if (nx < n && !check[nx]) {
			check[nx] = true;
			q.push(nx);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int s;
	cin >> s;
	s--;
	bfs(s);
	cout << ans << '\n';

	return 0;
}