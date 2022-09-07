#include <iostream>
#include <map>
using namespace std;
char a[101][101];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	map<char, char> map;
	map['.'] = '.';
	map['O'] = 'O';
	map['-'] = '|';
	map['|'] = '-';
	map['/'] = '\\';
	map['\\'] = '/';
	map['^'] = '<';
	map['<'] = 'v';
	map['v'] = '>';
	map['>'] = '^';

	for (int i = m - 1; i >= 0 ; i--) {
		for (int j = 0; j < n; j++) {
			cout << map[a[j][i]];
		}
		cout << '\n';
	}

	return 0;
}