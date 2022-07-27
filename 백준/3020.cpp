#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, h;
int crushed(vector<int>& obstacle, int height) {
	int left = 0, right = n / 2 - 1;
	int mini = n / 2;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (obstacle[mid] >= height) {
			mini = min(mini, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return n / 2 - mini;
}
int main() {
	cin >> n >> h;
	vector<int> down, up;
	for (int i = 0; i < n / 2; i++) {
		int a, b;
		cin >> a >> b;
		down.push_back(a);
		up.push_back(b);
	}
	sort(down.begin(), down.end());
	sort(up.begin(), up.end());
	
	int mini = 987654321;
	int cnt = 0;
	for (int i = 1; i <= h; i++) {
		int d = crushed(down, i);
		int u = crushed(up, h - i + 1);
		int du = d + u;
		if (mini > du) {
			mini = du;
			cnt = 1;
		}
		else if (mini == du) cnt++;
	}
	cout << mini << ' ' << cnt << '\n';


	return 0;
}