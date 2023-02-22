#include <iostream>
using namespace std;
int p_sum[100001];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		p_sum[i] = p_sum[i - 1] + x;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		cout << p_sum[y] - p_sum[x - 1] << '\n';
	}

	return 0;
}