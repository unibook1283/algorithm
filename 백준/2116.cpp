#include <iostream>
#include <vector>
using namespace std;
int a[10000][6];
int n;
int ans = 0;
int max_inline(int cnt, int bottom_index, int top_index) {
	int maxi = 0;
	for (int i = 0; i < 6; i++) {
		if (i == bottom_index || i == top_index) continue;
		maxi = max(maxi, a[cnt][i]);
	}
	return maxi;
}
int find_next_index(int num, int cnt) {
	for (int i = 0; i < 6; i++) {
		if (a[cnt + 1][i] == num) return i;
	}
}
void go(int cnt, int index, int sum) {
	if (cnt == n) {
		ans = max(ans, sum);
		return;
	}
	if (index == 0) {
		int mi = max_inline(cnt, 0, 5);
		int next_index = find_next_index(a[cnt][5], cnt);
		go(cnt + 1, next_index, sum + mi);
	}
	else if (index == 5) {
		int mi = max_inline(cnt, 5, 0);
		int next_index = find_next_index(a[cnt][0], cnt);
		go(cnt + 1, next_index, sum + mi);
	}
	else if (index == 1 || index == 2) {
		int mi = max_inline(cnt, index, index+2);	// B->D, C->E : 2沫究 坷弗率
		int next_index = find_next_index(a[cnt][index + 2], cnt);
		go(cnt + 1, next_index, sum + mi);
	}
	else if (index == 3 || index == 4) {
		int mi = max_inline(cnt, index, index - 2);	// D->B, E->C : 2沫究 哭率
		int next_index = find_next_index(a[cnt][index - 2], cnt);
		go(cnt + 1, next_index, sum + mi);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 6; i++) {
		go(0, i, 0);
	}
	cout << ans;

	return 0;
}