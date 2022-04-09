#include <iostream>
using namespace std;
int a[33][33];
long long d[33][33][3];
// 3번째 index: 파이프의 방향
// 0: 가로
// 1: 대각선
// 2: 세로
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
17070 파이프 옮기기1 에서는 dfs로 했었는데
제한이 더 큰 이 문제에서는 다이나믹으로 해야되구나.
다이나믹이 더 저렴하구나.

long long 말고 int로 해서 살짝 헤멤.
마지막 예제 입력에서.
*/