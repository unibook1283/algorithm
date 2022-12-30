#include <iostream>
#include <vector>
#include <map>
using namespace std;
void transform(string& str) {
	map<char, char> m;
	int cnt = 0;
	for (char& ch : str) {
		if (m.find(ch) == m.end())
			m[ch] = 'a' + (cnt++);
		ch = m[ch];
	}
}
bool similar(string a, string b) {
	transform(a);
	transform(b);
	return a == b;
}
int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (similar(v[i], v[j]))
				ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}