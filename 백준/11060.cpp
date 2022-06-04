#include <iostream>
#include <cstring>
using namespace std;
int a[1000];
int d[1000];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	memset(d, -1, sizeof(d));
	d[0] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (d[j] != -1 && j + a[j] >= i) {
				if (d[i] == -1 || d[i] > d[j] + 1) {
					d[i] = d[j] + 1;
				}
			}
		}
	}
	cout << d[n - 1] << '\n';

	return 0;
}