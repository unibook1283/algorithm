#include <iostream>
using namespace std;
char a[101][101];
int main() {
	int n;
	cin >> n;
	int hor = 0, ver = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == '.') cnt++;
			else {
				if (cnt >= 2) hor++;
				cnt = 0;
			}
		}
		if (cnt >= 2) hor++;
	}

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (a[j][i] == '.') cnt++;
			else {
				if (cnt >= 2) ver++;
				cnt = 0;
			}
		}
		if (cnt >= 2) ver++;
	}
	
	cout << hor << ' ' << ver << '\n';

	return 0;
}