#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<string> v, res;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (binary_search(v.begin(), v.end(), s)) {
			res.push_back(s);
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for (string s : res) {
		cout << s << '\n';
	}
	


	return 0;
}