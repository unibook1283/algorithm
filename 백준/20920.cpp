#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
map<string, int> cnt;
bool cmp(string a, string b) {
	if (cnt[a] == cnt[b]) {
		if (a.length() == b.length()) {
			return a < b;
		}
		return a.length() > b.length();
	}
	return cnt[a] > cnt[b];
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s.length() < m) continue;
		v.push_back(s);
		cnt[s]++;
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}

}