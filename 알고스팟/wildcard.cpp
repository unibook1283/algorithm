#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool match(const string& w, const string& s) {
	int pos = 0;
	while (pos < w.size() && pos < s.size()
		&& (w[pos] == '?' || w[pos] == s[pos]))
		pos++;
	if (pos == w.size())
		return pos == s.size();
	if (w[pos] == '*') {
		for (int skip = 0; pos + skip <= s.size(); skip++) {
			if (match(w.substr(pos + 1), s.substr(pos + skip)))
				return true;
		}
	}
	return false;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		string w;
		cin >> w;
		int n;
		cin >> n;
		vector<string> v;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			if (match(w, s)) {
				v.push_back(s);
			}
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << '\n';
		}
	}

	return 0;
}