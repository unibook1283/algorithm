#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
int bfs(vector<int>& perm) {
	int n = perm.size();
	vector<int> sorted = perm;
	sort(sorted.begin(), sorted.end());

	map<vector<int>, int> distance;
	queue<vector<int>> q;
	q.push(perm);
	distance[perm] = 0;
	while (!q.empty()) {
		vector<int> here = q.front();
		q.pop();
		if (here == sorted) return distance[here];
		int d = distance[here];
		for (int i = 0; i < n; i++) {
			for (int j = i + 2; j <= n; j++) {
				reverse(here.begin() + i, here.begin() + j);
				if (distance.count(here) == 0) {
					distance[here] = d + 1;
					q.push(here);
				}
				reverse(here.begin() + i, here.begin() + j);
			}
		}
	}
	return -1;
}
int main() {
	int c, ans = 0;
	cin >> c;
	while (c--) {
		int n;
		cin >> n;
		vector<int> perm(n);
		for (int i = 0; i < n; i++) {
			cin >> perm[i];
		}
		ans = bfs(perm);
		cout << ans << '\n';
	}

	return 0;
}