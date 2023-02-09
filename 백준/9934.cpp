#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int n;
vector<int> ans[11];
void go(vector<int> v, int level) {
	int len = v.size();
	int mid = len / 2;
	ans[level].push_back(v[mid]);
	if (len == 1) return;
	vector<int> left(v.begin(), v.begin() + mid);
	vector<int> right(v.begin() + mid + 1, v.end());
	go(left, level + 1);
	go(right, level + 1);
}
void print_ans() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}
int main() {
	cin >> n;
	vector<int> v;
	for (int i = 0; i < pow(2, n) - 1; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	go(v, 0);
	print_ans();

	return 0;
}