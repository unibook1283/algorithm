#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;

	map<string, int> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		s.erase(0, s.find('.') + 1);

		if (m.find(s) != m.end()) {
			m[s]++;
		}
		m.insert({ s,1 });
	}

	for (auto i : m) {
		cout << i.first << ' ' << i.second << '\n';
	}



	return 0;
}