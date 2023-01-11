#include <iostream>
using namespace std;
bool check[20001];
int main() {
	int n, m;
	string s;
	cin >> n >> m >> s;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'P') {
			for (int range = i - m; range <= i + m; range++) {
				if (range < 0 || range >= n) continue;
				if (s[range] == 'H' && !check[range]) {
					check[range] = true;
					ans++;
					break;
				}
			}
		}
	}
	cout << ans << '\n';

	return 0;
}