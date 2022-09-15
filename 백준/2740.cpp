#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m, k;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	cin >> m >> k;
	vector<vector<int>> b(m, vector<int>(k));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int sum = 0;
			for (int k = 0; k < m; k++) {
				sum += a[i][k] * b[k][j];
			}
			cout << sum << ' ';
		}
		cout << '\n';
	}
}