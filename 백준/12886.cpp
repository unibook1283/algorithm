#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int small[] = { 0,1,0 };
int big[] = { 1,2,2 };
int bfs(vector<int> &v, vector<int> &goal) {
	map<vector<int>, bool> check;
	check[v] = true;
	queue<vector<int>> q;
	q.push(v);
	while (!q.empty()) {
		vector<int> stones = q.front();
		q.pop();
		sort(stones.begin(), stones.end());
		for (int i = 0; i < 3; i++) {
			int x = small[i];
			int y = big[i];
			int pass = stones[x];
			stones[x] += pass;
			stones[y] -= pass;
			if (stones == goal) return 1;
			if (check[stones] == false) {
				check[stones] = true;
				q.push(stones);
			}
			stones[x] -= pass;
			stones[y] += pass;
		}
	}
	return 0;
}
int main() {
	vector<int> v(3);
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		cin >> v[i];
		sum += v[i];
	}
	if (sum % 3 != 0) {
		cout << 0;
		return 0;
	}
	if (v[0] == v[1] && v[1] == v[2]) {
		cout << 1;
		return 0;
	}
	vector<int> goal(3);
	for (int i = 0; i < 3; i++) {
		goal[i] = sum / 3;
	}
	int ans = bfs(v, goal);
	cout << ans;

	return 0;
}