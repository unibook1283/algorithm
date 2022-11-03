#include <iostream>
#include <cstring>
using namespace std;
double cache[1001][2001];
int n, m;
double climb(int days, int climbed) {
	if (days == m) return climbed >= n ? 1 : 0;
	double& ret = cache[days][climbed];
	if (ret != -1) return ret;
	ret = 0.25 * climb(days + 1, climbed + 1) + 0.75 * climb(days + 1, climbed + 2);
	return ret;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 1000; i++) {
			for (int j = 0; j < 2000; j++) {
				cache[i][j] = -1;
			}
		}
		cin>> n >> m;
		cout.precision(11);
		cout << climb(0, 0) << '\n';
	}

	return 0;
}