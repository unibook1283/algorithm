#include <stdio.h>
using namespace std;
int a[101][101];
void turn(int x, int y) {
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			a[i][j] = !a[i][j];
		}
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	int answer = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (a[i][j] == 1) {
				turn(i, j);
				answer++;
			}
		}
	}

	printf("%d\n", answer);

	return 0;
}