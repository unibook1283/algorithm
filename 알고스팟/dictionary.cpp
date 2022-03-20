#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> adj;
void makeGraph(const vector<string>& words) {
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	for (int j = 1; j < words.size(); j++) {
		int i = j - 1;
		int len = min(words[i].size(), words[j].size());
		for (int k = 0; k < len; k++) {
			if (words[i][k] != words[j][k]) {
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				adj[a][b] = 1;
				break;
			}
		}
	}
}
vector<int> visited, order;
void dfs(int x) {
	visited[x] = 1;
	for (int i = 0; i < adj.size(); i++) {
		if (adj[x][i] && !visited[i]) {
			dfs(i);
		}
	}
	order.push_back(x);
}
vector<int> topologySort() {
	int m = adj.size();
	visited = vector<int>(m, 0);
	order.clear();
	for (int i = 0; i < m; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	reverse(order.begin(), order.end());
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			if (adj[order[j]][order[i]]) {
				return vector<int>();
			}
		}
	}

	return order;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int c;
	cin >> c;
	while (c--) {
		int n;
		cin >> n;
		vector<string> words(n);
		for (auto& w : words) {		// string w로 하면 안되네
			cin >> w;
		}
		makeGraph(words);

		auto orders = topologySort();
		if (orders.empty()) {
			cout << "INVALID HYPOTHESIS\n";
		}
		else {
			for (auto& o : orders) {
				cout << static_cast<char>(o + 'a');
			}
			cout << '\n';
		}
	}



	return 0;
}