#include <iostream>
#include <cstring>
using namespace std;
int n;
int a[6];
long long cache[11][11][11][11][11][6][6];
int sum = 0;
long long go(int cnt, int prev, int curr) {
	if (cnt == sum) {
		return 1;
	}
	long long& ret = cache[a[1]][a[2]][a[3]][a[4]][a[5]][prev][curr];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0 || i == prev || i == curr) continue;
		a[i]--;
		ret += go(cnt + 1, curr, i);
		a[i]++;
	}
	return ret;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	memset(cache, -1, sizeof(cache));
	cout << go(0, 0, 0) << '\n';

	return 0;
}