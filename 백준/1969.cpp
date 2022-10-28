#include <iostream>
#include <map>
using namespace std;
map<char, int> ma[51];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			ma[j][s[j]]++;
		}
	}
	string ans;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		char M_ch;
		int M_cnt = 0;
		for (auto iter = ma[i].begin(); iter != ma[i].end(); iter++) {
			if (iter->second > M_cnt) {
				M_ch = iter->first;
				M_cnt = iter->second;
			}
		}
		ans += M_ch;
		cnt += M_cnt;
	}
	cout << ans << '\n';
	cout << n * m - cnt << '\n';

	return 0;
}