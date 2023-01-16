#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> graph[51];
int dfs(int x) {
	int children = graph[x].size();
	vector<int> v;
	for (int i = 0; i < children; i++) {
		int nx = graph[x][i];
		v.push_back(dfs(nx));
	}
	sort(v.begin(), v.end());
	int ret = 0;
	for (int i = 0; i < children; i++) {
		ret = max(ret, v[i] + (children - i));
	}
	return ret;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == -1) continue;
		graph[x].push_back(i);
	}
	cout << dfs(0) << '\n';

	return 0;
}