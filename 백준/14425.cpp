#include <iostream>
#include <map>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	map<string, bool> ma;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		ma[str] = true;
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (ma[str]) ans++;
	}
	cout << ans << '\n';

	return 0;
}