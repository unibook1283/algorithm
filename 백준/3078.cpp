#include <iostream>
#include <queue>
using namespace std;
queue<int> q[21];
int main() {
	int n, k;
	cin >> n >> k;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int len = s.length();
		while (!q[len].empty() && i - q[len].front() > k)
			q[len].pop();
		ans += q[len].size();
		q[len].push(i);
	}
	cout << ans << '\n';

	return 0;
}