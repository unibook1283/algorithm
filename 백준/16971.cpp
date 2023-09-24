#include <iostream>
using namespace std;
int a[1001][1001];
long long line_sum[2][1001];	// 0 : row, 1 : col
						// 1*a[0] + 2*a[1] + 2*a[2] + ... + 2*a[n-2] + 1*a[n-1]
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j == 0 || j == m - 1) {
				line_sum[0][i] += a[i][j];
			}
			else {
				line_sum[0][i] += 2 * a[i][j];
			}
			if (i == 0 || i == n - 1) {
				line_sum[1][j] += a[i][j];
			}
			else {
				line_sum[1][j] += 2 * a[i][j];
			}
		}
	}

	long long total_sum = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0 || i == n - 1)
			total_sum += line_sum[0][i];
		else
			total_sum += 2 * line_sum[0][i];
	}

	long long answer = total_sum;
	for (int i = 1; i < n - 1; i++) {
		// 0번 행과 i번 행을 교환
		long long sum = total_sum;
		sum += line_sum[0][0];
		sum -= line_sum[0][i];
		answer = max(answer, sum);
		// n-1번 행과 i번 행을 교환
		sum = total_sum;
		sum += line_sum[0][n - 1];
		sum -= line_sum[0][i];
		answer = max(answer, sum);
	}
	for (int i = 1; i < m - 1; i++) {
		// 0번 열과 i번 열을 교환
		long long sum = total_sum;
		sum += line_sum[1][0];
		sum -= line_sum[1][i];
		answer = max(answer, sum);
		// m-1번 열과 i번 열을 교환
		sum = total_sum;
		sum += line_sum[1][m - 1];
		sum -= line_sum[1][i];
		answer = max(answer, sum);
	}
	cout << answer << '\n';

	return 0;
}