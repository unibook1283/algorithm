#include <iostream>
#include <cstring>
using namespace std;
int a[1001];
int d[1001];
char boj[3] = { 'B', 'O', 'J' };
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	memset(d, -1, sizeof(d));
	d[0] = 0;
	for (int i = 1; i < n; i++) {
		int prev_index;
		for (int j = 0; j < 3; j++) {
			if (s[i] == boj[j]) {
				prev_index = (j + 2) % 3;
				break;
			}
		}
		for (int j = 0; j < i; j++) {
			if (d[j] == -1) continue;
			if (s[j] == boj[prev_index]) {
				if (d[i] == -1 || d[i] > d[j] + (i - j) * (i - j))
					d[i] = d[j] + (i - j) * (i - j);
			}
		}
	}
	cout << d[n - 1];

	return 0;
}