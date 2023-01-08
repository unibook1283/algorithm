#include <iostream>
#include <unordered_set>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	unordered_set<string> s;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		s.insert(str);
	}
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		int prev = 0;
		while (1) {
			int index = str.find(',', prev);
			if (index == -1) break;
			string keyword = str.substr(prev, index - prev);
			prev = index + 1;
			s.erase(keyword);
		}
		string keyword = str.substr(prev);
		s.erase(keyword);
		cout << s.size() << '\n';
	}

	return 0;
}