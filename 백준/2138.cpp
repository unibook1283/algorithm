#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100001];
int b[100001];
int temp[100001];
int n;
void push(int x) {
	for (int i = x - 1; i <= x + 1; i++) {
		if (i < 0 || i >= n) continue;
		temp[i] = !temp[i];
	};
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%1d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%1d", &b[i]);
	}

	copy(a, a + n, temp);
	int ans[2] = { 0, 1 };
	for (int i = 1; i < n; i++) {
		if (temp[i - 1] != b[i - 1]) {
			push(i);
			ans[0]++;
		}
	}
	if (temp[n - 1] != b[n - 1]) ans[0] = -1;

	copy(a, a + n, temp);
	push(0);
	for (int i = 1; i < n; i++) {
		if (temp[i - 1] != b[i - 1]) {
			push(i);
			ans[1]++;
		}
	}
	if (temp[n - 1] != b[n - 1]) ans[1] = -1;

	if (ans[0] == -1 && ans[1] == -1) printf("-1\n");
	else if (ans[0] == -1) printf("%d\n", ans[1]);
	else if (ans[1] == -1) printf("%d\n", ans[0]);
	else printf("%d\n", min(ans[1], ans[0]));

	return 0;
}