#include <iostream>
using namespace std;
bool a[30][30];
int main() {
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char from, to;
		string is;
		cin >> from >> is >> to;
		a[from - 'a'][to - 'a'] = true;
	}

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			for (int k = 0; k < 26; k++) {
				a[j][k] = (a[j][k] | (a[j][i] & a[i][k]));
			}
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		char from, to;
		string is;
		cin >> from >> is >> to;
		if (a[from - 'a'][to - 'a']) cout << "T\n";
		else cout << "F\n";
	}

	return 0;
}