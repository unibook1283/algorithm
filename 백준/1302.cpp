#include <iostream>
#include <map>
using namespace std;
int main() {
	int n;
	cin >> n;
	map <string, int> m;
	while (n--) {
		string s;
		cin >> s;
		m[s]++;
	}
	int cnt;
	for (auto p : m) {
		cnt = max(cnt, p.second);
	}
	for (auto p : m) {
		if (p.second == cnt) {
			cout << p.first << '\n';
			break;
		}
	}

	return 0;
}
/*
map�� key���� �������� �������� ���ĵȴ�.
*/