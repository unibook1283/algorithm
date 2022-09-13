#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	map<string, int> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		m[s] = i;
	}

	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int point = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (m[v[i]] < m[v[j]]) {
				point++;
			}
		}
	}
	cout << point << '/' << n * (n - 1) / 2 << '\n';

	return 0;
}