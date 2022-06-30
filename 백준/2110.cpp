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
	int left = 1, right = 0;	// ���� ������ �� ������ ������ �Ÿ�
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
possible Ȯ���ϴ� �κ��� �� �������ϳ�.
���� �����ڷῡ�� �̷��� �Ǿ�����.
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