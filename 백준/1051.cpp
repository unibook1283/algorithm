#include <stdio.h>
#include <iostream>
using namespace std;
int a[50][50];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	int ans = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 1; k < min(n, m); k++) {
				if (i + k < n && j + k < m) {
					if (a[i + k][j] == a[i][j] && a[i][j + k] == a[i][j] && a[i + k][j + k] == a[i][j]) {
						ans = max(ans, (k + 1) * (k + 1));
					}
				}
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}