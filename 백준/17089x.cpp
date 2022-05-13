#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool a[4000][4000];
bool areFriends(int abc[3]) {
	for (int i = 0; i < 3; i++) {
		if (a[abc[i]][abc[(i + 1) % 3]] == false) return false;
	}
	return true;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int f, s;
		cin >> f >> s;
		f--; s--;
		a[f][s] = true;
		a[s][f] = true;
	}
	vector<int> v;
	for (int i = 0; i < n - 3; i++) 
		v.push_back(0);
	for (int i = 0; i < 3; i++)
		v.push_back(1);

	int ans = -1;
	do {
		int abc[3];
		int j = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] == 1) abc[j++] = i;
		}
		if (!areFriends(abc)) continue;

		int sum = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < n; j++) {
				if (a[abc[i]][j]) sum++;
			}
		}
		sum -= 6;

		if (ans == -1 || ans > sum) ans = sum;
	} while (next_permutation(v.begin(), v.end()));

	cout << ans << '\n';

	return 0;
}