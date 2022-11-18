#include <stdio.h>
#include <cstring>
using namespace std;
int a[2001];
int cache[2001][2001];
int is_palindrome(int start, int end) {
	if (start >= end) return 1;
	int& ret = cache[start][end];
	if (ret != -1) return ret;
	ret = 0;
	if (a[start] == a[end])
		ret = is_palindrome(start + 1, end - 1);
	return ret;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	int m;
	scanf("%d", &m);
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < m; i++) {
		int start, end;
		scanf("%d%d", &start, &end);
		start--; end--;
		printf("%d\n", is_palindrome(start, end));
	}

	return 0;
}