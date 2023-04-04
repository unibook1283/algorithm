#include <iostream>
#include <vector>
using namespace std;
vector<pair<pair<int, int>, int>> graph; // (a, b, cost)
int parent[1001];
int getParent(int x) {
	if (x == parent[x]) return x;
	return getParent(parent[x]);
}
bool sameParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	return x == y;
}
void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x > y) parent[y] = x;
	else parent[x] = y;
}
void initParent(int n) {
	for (int i = 1; i <= n; i++)
		parent[i] = i;
}
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		graph.push_back({ { a,b }, i });
	}

	bool end = false;
	while (k--) {
		if (end) {
			cout << 0 << ' ';
			continue;
		}
		initParent(n);

		int sum = 0;
		int edgeCount = 0;
		int indexToRemove = -1;
		for (int i = 0; i < graph.size(); i++) {
			int a = graph[i].first.first;
			int b = graph[i].first.second;
			int cost = graph[i].second;
			if (!sameParent(a, b)) {
				unionParent(a, b);
				edgeCount++;
				sum += cost;
				if (indexToRemove == -1)
					indexToRemove = i;
			}
		}
		if (edgeCount == n - 1) {
			graph.erase(graph.begin() + indexToRemove);
			cout << sum << ' ';
		}
		else {
			cout << 0 << ' ';
			end = true;
		}
	}
	cout << '\n';

	return 0;
}