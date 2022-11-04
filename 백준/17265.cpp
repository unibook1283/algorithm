#include <iostream>
#include <vector>
using namespace std;
char a[5][5];
int mini = 987654321, maxi = -987654321;
int dx[] = { 1,0 };
int dy[] = { 0,1 };
int n;
int get_result(vector<char> ops, vector<int> nums) {
	int res = nums[0];
	for (int i = 0; i < n - 1; i++) {
		if (ops[i] == '+') res += nums[i + 1];
		else if (ops[i] == '-') res -= nums[i + 1];
		else res *= nums[i + 1];
	}
	return res;
}
void go(int x, int y, int cnt, vector<char>& ops, vector<int>& nums) {
	if (cnt % 2 == 0) nums.push_back(a[x][y] - '0');
	else ops.push_back(a[x][y]);
	if (x == n - 1 && y == n - 1) {
		int res = get_result(ops, nums);
		mini = min(mini, res);
		maxi = max(maxi, res);
		nums.pop_back();
		return;
	}
	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			go(nx, ny, cnt + 1, ops, nums);
		}
	}
	if (cnt % 2 == 0) nums.pop_back();
	else ops.pop_back();
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	vector<char> ops;
	vector<int> nums;
	go(0, 0, 0, ops, nums);
	cout << maxi << ' ' << mini << '\n';

	return 0;
}