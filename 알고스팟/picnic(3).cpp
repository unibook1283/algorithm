#include <iostream>
#include <cstring>
bool areFriends[10][10];
bool check[10];
int n, m;
using namespace std;
int go() {
	int first = -1;
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			first = i;
			break;
		}
	}
	if (first == -1) return 1;
	int cnt = 0;
	for (int i = first + 1; i < n; i++) {
		if (!check[i] && areFriends[first][i]) {
			check[first] = check[i] = true;
			cnt += go();
			check[first] = check[i] = false;
		}
	}
	return cnt;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(areFriends, false, sizeof(areFriends));
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			areFriends[a][b] = true;
			areFriends[b][a] = true;
		}
		cout << go() << '\n';
	}

	return 0;
}