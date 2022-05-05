#include <iostream>
#include <cstring>
using namespace std;
bool areFriends[10][10];
int n, m;
int removeRedundancy(int x) {
	for (int i = 1; i <= n / 2; i++) {
		x /= i;
	}
	return x;
}
bool finished(bool taken[10]) {
	for (int i = 0; i < n; i++) {
		if (taken[i] == false) {
			return false;
		}
	}
	return true;
}
int countParings(bool taken[10]) {
	if (finished(taken)) return 1;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (!taken[i] && !taken[j] && areFriends[i][j]) {
				taken[i] = taken[j] = true;
				ret += countParings(taken);
				taken[i] = taken[j] = false;
			}
		}
	}
	return ret;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(areFriends, false, sizeof(areFriends));
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			areFriends[a][b] = true;
			areFriends[b][a] = true;
		}
		bool taken[10] = { 0, };
		int res = countParings(taken);
		cout << removeRedundancy(res) << '\n';;
	}

	return 0;
}
/*
책이랑 좀 다르게 품. 그냥 n!로 나눠줘서 순서가 다름으로 인한 중복을 제거함. 잘한듯.
*/