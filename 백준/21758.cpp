#include <iostream>
using namespace std;
int a[100002];
int sum[100002];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}

	int ans = 0;
	// �� - �� - ����
	for (int i = 2; i < n; i++) {	// i : ��� ���� ��ġ
		ans = max(ans, (sum[n] - sum[1] - a[i]) + (sum[n] - sum[i]));
	}
	
	// �� - ���� - ��
	for (int i = 2; i < n; i++) {	// i : ������ ��ġ
		ans = max(ans, (sum[i] - sum[1]) + (sum[n - 1] - sum[i - 1]));
	}

	// ���� - �� -��
	for (int i = 2; i < n; i++) {	// i : ��� ���� ��ġ
		ans = max(ans, (sum[i - 1] - sum[0]) + (sum[n - 1] - sum[0] - a[i]));
	}

	cout << ans << '\n';

	return 0;
}