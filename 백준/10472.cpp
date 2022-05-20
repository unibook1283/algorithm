#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int d[(1 << 9)];
vector<vector<int>> adj = {
	{0,1,3},{0,1,2,4},{1,2,5},
	{0,3,4,6},{1,3,4,5,7},{2,4,5,8},
	{3,6,7},{4,6,7,8},{5,7,8}
};
int click(int a, int index) {
	for (int i = 0; i < adj[index].size(); i++) {
		int inverse = adj[index][i];
		a ^= (1 << inverse);
	}
	return a;
}
void bfs(int a) {
	d[a] = 0;
	queue<int> q;
	q.push(a);
	while (!q.empty()) {
		a = q.front();
		q.pop();
		if (a == 0) return;
		for (int i = 0; i < 9; i++) {
			int clicked = click(a, i);
			if (d[clicked] == -1) {
				d[clicked] = d[a] + 1;
				q.push(clicked);
			}
			
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(d, -1, sizeof(d));
		int a = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				char ch;
				cin >> ch;
				if (ch == '*') {
					int k = 1;
					a += (k << (3 * i + j));
				}
			}
		}
		bfs(a);
		cout << d[0] << '\n';
	}

	return 0;
}