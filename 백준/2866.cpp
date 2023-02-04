#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
char a[1001][1001];
void erase_uppermost(vector<string>& v) {
	for (int i = 0; i < v.size(); i++) {
		v[i].erase(0, 1);
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	vector<string> v(m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			v[i] += a[j][i];
		}
	}

	for (int count = 0; count < n; count++) {
		erase_uppermost(v);
		sort(v.begin(), v.end());
		set<string> s;
		for (int i = 0; i < m; i++) {
			if (s.find(v[i]) != s.end()) {
				cout << count << '\n';
				return 0;
			}
			else s.insert(v[i]);
		}
	}

	return 0;
}