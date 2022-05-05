#include <iostream>
#include <vector>
using namespace std;
char a[5][5];
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
bool go(int x, int y, string s, int index) {
	if (index == s.size()) return true;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
			if (a[nx][ny] == s[index]) {
				if (go(nx, ny, s, index + 1)) return true;
			}
		}
	}
	return false;
}
int main() {
	int c;
	cin >> c;
	while (c--) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> a[i][j];
			}
		}
		int n;
		cin >> n;
		vector<string> v(n);
		vector<bool> pos(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < n; k++) {
					if (a[i][j] == v[k][0] && !pos[k]) {
						pos[k] = go(i, j, v[k], 1);
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout << v[i] << ' ';
			pos[i] ? cout << "YES" : cout << "NO";
			cout << '\n';
		}
	}


	return 0;
}