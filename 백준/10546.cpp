#include <iostream>
#include <map>
using namespace std;
int main() {
	int n;
	cin >> n;
	map<string, int> m;
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		m[name]++;
	}
	for (int i = 0; i < n - 1; i++) {
		string name;
		cin >> name;
		m[name]--;
	}
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second > 0) cout << iter->first << '\n';
	}

	return 0;
}