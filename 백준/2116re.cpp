#include <iostream>
#include <vector>
using namespace std;
int a[10000][6];
int n;
int ans = 0;
int bottom_to_top_index[6] = { 5,3,4,1,2,0 };
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
	int mi = max_inline(cnt, index, bottom_to_top_index[index]);
	int next_index = find_next_index(a[cnt][bottom_to_top_index[index]], cnt);
	go(cnt + 1, next_index, sum + mi);
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
/*
int bottom_to_top_index[6] = { 5,3,4,1,2,0 };
이걸 이용해서 코드 길이를 획기적(내 기준)으로 줄임.
원래거랑 비교해봐.
*/