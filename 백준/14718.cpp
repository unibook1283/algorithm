#include <iostream>
#include <vector>
using namespace std;
int a[101][3];
int n, k;
int ans = 987654321;
bool possible_k(vector<int> &v) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		bool ok = true;
		for (int j = 0; j < 3; j++) {
			if (a[i][j] > v[j]) {
				ok = false;
				break;
			}
		}
		if (ok) cnt++;
	}
	return cnt >= k;
}
int cal_total_stat(vector<int>& v) {
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}
	return sum;
}
void go(int index, vector<int> &v) {
	if (index == 3) {
		if (possible_k(v)) {
			int total_stat = cal_total_stat(v);
			ans = min(ans, total_stat);
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		v.push_back(a[i][index]);
		go(index + 1, v);
		v.pop_back();
	}
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	vector<int> v;
	go(0, v);
	cout << ans << '\n';

	return 0;
}