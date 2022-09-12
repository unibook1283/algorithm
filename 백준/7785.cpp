#include <iostream>
#include <map>
using namespace std;
int main() {
	int n;
	cin >> n;
	map<string, bool> m;
	for (int i = 0; i < n; i++) {
		string name, el;
		cin >> name >> el;
		if (el == "enter") {
			m[name] = true;
		}
		else {
			m[name] = false;
		}
	}
	for (auto i = m.rbegin(); i != m.rend(); i++) {
		if (i->second) cout << i->first << '\n';
	}

	return 0;
}