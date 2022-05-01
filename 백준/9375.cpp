#include <iostream>
#include <map>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map <string, int> m;
		for (int i = 0; i < n; i++) {
			string name, cat;
			cin >> name >> cat;
			if (m.find(cat) == m.end()) {
				m.insert({cat, 1});
			}
			else {
				m[cat]++;
			}
		}
		int ans = 1;
		for (auto i : m) {
			ans *= i.second + 1;
		}
		cout << --ans << '\n';
	}

	return 0;
}