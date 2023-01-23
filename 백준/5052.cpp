#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool is_prefix(string a, string b) {
	return a == b.substr(0, a.length());
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<string> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		
		bool consistency = true;
		for (int i = 0; i < n - 1; i++) {
			if (is_prefix(v[i], v[i + 1])) {
				consistency = false;
				break;
			}
		}
		if (consistency) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}