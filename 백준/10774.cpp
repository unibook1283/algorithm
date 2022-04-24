#include <iostream>
#include <vector>
using namespace std;
char a[1000000];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		char required_size;
		int num;
		cin >> required_size >> num;
		if (required_size == 'S') {
			if (a[num] != 'X') {
				cnt++;
				a[num] = 'X';
			}
		}
		else if (required_size == 'M') {
			if (a[num] == 'L' || a[num] == 'M') {
				cnt++;
				a[num] = 'X';
			}
		}
		else if (required_size == 'L') {
			if (a[num] == 'L') {
				cnt++;
				a[num] = 'X';
			}
		}
	}
	cout << cnt << '\n';

	return 0;
}