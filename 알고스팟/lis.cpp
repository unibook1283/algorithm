#include <iostream>
#include <cstring>
using namespace std;
int n;
int a[501];
int cache[501];
//start를 선택했을 때, lis의 길이
int lis(int start) {
	int& ret = cache[start + 1];
	if (ret != -1) return ret;
	ret = 1;
	for (int next = start + 1; next < n; next++) {
		if (start == -1 || a[start] < a[next]) {
			ret = max(ret, 1 + lis(next));
		}
	}
	return ret;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << lis(-1) - 1 << '\n';
	}

	return 0;
}