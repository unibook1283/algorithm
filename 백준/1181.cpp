#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string u, string v) {
	if (u.length() == v.length()) {
		return u < v;
	}
	return u.length() < v.length();
}
int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), cmp);
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}

	return 0;
}