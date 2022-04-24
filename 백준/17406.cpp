#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int r[6], c[6], s[6];
int n, m, k;
void rotate(int index, vector<vector<int>> &copy_a) {
	int row = r[index] - 1;
	int col = c[index] - 1;
	int ss = s[index];
	for (int i = 1; i <= ss; i++) {
		int temp = copy_a[row - i][col + i];
		for (int j = i; j > -i; j--) {
			copy_a[row - i][col + j] = copy_a[row - i][col + j - 1];
		}
		for (int j = -i; j < i; j++) {
			copy_a[row + j][col - i] = copy_a[row + j + 1][col - i];
		}
		for (int j = -i; j < i; j++) {
			copy_a[row + i][col + j] = copy_a[row + i][col + j + 1];
		}
		for (int j = i; j > -i; j--) {
			copy_a[row + j][col + i] = copy_a[row + j - 1][col + i];
		}
		copy_a[row - i + 1][col + i] = temp;
	}
}
int cal_ary_val(vector<vector<int>> &copy_a) {
	int res = 987654321;
	for (int i = 0; i < n; i++) {
		int val = 0;
		for (int j = 0; j < m; j++) {
			val += copy_a[i][j];
		}
		res = min(res, val);
	}
	return res;
}
int main() {
	cin >> n >> m >> k;
	vector<vector<int>>a(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	vector<int> perm;
	for (int i = 0; i < k; i++) {
		cin >> r[i] >> c[i] >> s[i];
		perm.push_back(i);
	}

	int ans = 987654321;
	do {
		vector<vector<int>> copy_a(n, vector<int>(m, 0));
		copy(a.begin(), a.end(), copy_a.begin());

		for (int i = 0; i < k; i++) {
			rotate(perm[i], copy_a);
		}

		int ary_val = cal_ary_val(copy_a);
		ans = min(ans, ary_val);
	} while(next_permutation(perm.begin(), perm.end()));

	cout << ans << '\n';

	return 0;
}