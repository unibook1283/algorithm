#include <iostream>
using namespace std;
int a[33][33];
long long d[33][33][3];
// 3��° index: �������� ����
// 0: ����
// 1: �밢��
// 2: ����
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	d[1][2][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == 1) continue;

			d[i][j][0] += d[i][j - 1][0] + d[i][j - 1][1];
			if (a[i - 1][j] == 0 && a[i][j - 1] == 0) {
				d[i][j][1] += d[i - 1][j - 1][0] + d[i - 1][j - 1][1] + d[i - 1][j - 1][2];
			}
			d[i][j][2] += d[i - 1][j][1] + d[i - 1][j][2];
		}
	}
	cout << d[n][n][0] + d[n][n][1] + d[n][n][2] << '\n';
	
	return 0;
}
/*
17070 ������ �ű��1 ������ dfs�� �߾��µ�
������ �� ū �� ���������� ���̳������� �ؾߵǱ���.
���̳����� �� �����ϱ���.

long long ���� int�� �ؼ� ��¦ ���.
������ ���� �Է¿���.
*/