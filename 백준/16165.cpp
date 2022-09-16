#include <iostream>
#include <map>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;

	map<string, string> m;	// (¸â¹ö ÀÌ¸§, ÆÀ ÀÌ¸§)
	while (n--) {
		string team;
		cin >> team;
		int m_cnt;
		cin >> m_cnt;
		for (int i = 0; i < m_cnt; i++) {
			string member;
			cin >> member;
			m[member] = team;
		}
	}
	
	while (k--) {
		string s;
		cin >> s;
		int q;
		cin >> q;
		if (q == 0) {
			for (auto iter = m.begin(); iter != m.end(); iter++) {
				if (iter->second == s) cout << iter->first << '\n';
			}
		}
		else {
			cout << m[s] << '\n';
		}
	}

	return 0;
}