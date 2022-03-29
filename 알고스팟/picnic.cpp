#include <iostream>
#include <vector>
using namespace std;
bool areFriends[10][10];
int n, m;
int countParings(vector<bool>& taken) {
	int firstFree = -1;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	if (firstFree == -1) {
		cout << "end" << '\n';
		return 1;
	}
	int ret = 0;
	for (int i = firstFree + 1; i < n; i++) {
		if (!taken[i] && areFriends[firstFree][i]) {
			cout << "i: " << i << ", firstFree: " << firstFree << '\n';
			taken[firstFree] = taken[i] = true;
			ret += countParings(taken);
			taken[firstFree] = taken[i] = false;
		}
	}
	return ret;
	/*
	bool finished = true;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) finished = false;
	}
	if (finished) return 1;
	int ret = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (!taken[i] && !taken[j] && areFriends[i][j]) {
				taken[i] = taken[j] = true;
				ret += countParings(taken);
				taken[i] = taken[j] = false;
			}
		}
	}
	return ret;
	*/
}
int main() {
	int c;
	cin >> c;
	while (c--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			areFriends[a][b] = true;
			areFriends[b][a] = true;
		}
		vector<bool> taken(n);
		for (int i = 0; i < n; i++) {
			taken[i] = false;
		}
		cout << countParings(taken) << '\n';
	}

	return 0;
}