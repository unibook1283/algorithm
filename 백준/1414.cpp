#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, pair<int, int>>> graph; // (dist, (from, to))
int parent[51];
int get_parent(int x) {
	if (x == parent[x]) return x;
	return get_parent(parent[x]);
}
bool same_parent(int x, int y) {
	x = get_parent(x);
	y = get_parent(y);
	return x == y;
}
void union_parent(int x, int y) {
	x = get_parent(x);
	y = get_parent(y);
	if (x > y) parent[y] = x;
	else parent[x] = y;
}
int main() {
	int n;
	cin >> n;
	int total = 0, answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char ch;
			cin >> ch;
			if (ch == '0') continue;

			int dist;
			if ('a' <= ch && ch <= 'z') {
				dist = ch - 'a' + 1;
			}
			else {
				dist = ch - 'A' + 27;
			}

			if (i == j) {
				answer += dist;
			}
			else {
				graph.push_back({ dist,{i,j} });
				total += dist;
			}
		}
	}

	sort(graph.begin(), graph.end());

	for (int i = 0; i < n; i++)
		parent[i] = i;

	int sum = 0, cnt = 0;
	for (int i = 0; i < graph.size(); i++) {
		int dist = graph[i].first;
		int x = graph[i].second.first;
		int y = graph[i].second.second;
		if (!same_parent(x, y)) {
			union_parent(x, y);
			sum += dist;
			cnt++;
		}
	}

	if (cnt == n - 1)
		answer += total - sum;
	else
		answer = -1;
	cout << answer << '\n';

	return 0;
}