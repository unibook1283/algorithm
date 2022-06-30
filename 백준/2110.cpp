#include <iostream>
#include <algorithm>
using namespace std;
int a[200001];
int n, c;
bool possible(int d) {
	int i = 0, cnt = 1;
	int x = a[0];
	while (1) {
		int nx = x + d;
		while (nx > a[i]) {
			i++;
			if (i >= n) return false;
		}
		x = a[i];
		cnt++;
		if (cnt == c) return true;
	}
	return false;
}
int main() {
	cin >> n >> c;
	int left = 1, right = 0;	// 가장 인접한 두 공유기 사이의 거리
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		right = max(right, a[i]);
	}
	sort(a, a + n);

	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (possible(mid)) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans << '\n';

	return 0;
}
/*
possible 확인하는 부분이 좀 지저분하네.
백준 강의자료에는 이렇게 되어있음.
bool possible(vector<int> &a, int c, int x) {
	int cnt = 1;
	int last = a[0];
	for (int house : a) {
		if (house - last >= x) {
			cnt += 1;
			last = house;
		}
	}
	return cnt >= c;
}
*/