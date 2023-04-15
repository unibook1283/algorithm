#include <iostream>
#include <vector>
using namespace std;
const int INF = 987654321;
int graph[201][201];
int n, m;
void init_graph() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			graph[i][j] = INF;
		}
	}
}
int main() {
	cin >> n >> m;
	init_graph();
	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		graph[a][b] = t;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	}

	int k;
	cin >> k;
	vector<int> v(k);
	for (int i = 0; i < k; i++) {
		cin >> v[i];
	}

	int min_max_sum = INF;
	vector<int> answer;
	for (int i = 1; i <= n; i++) {
		int max_sum = 0;
		for (int friend_city : v) {
			if (i == friend_city) continue;
			int sum = graph[i][friend_city] + graph[friend_city][i];
			max_sum = max(max_sum, sum);
		}
		if (min_max_sum > max_sum) {
			answer.clear();
			answer.push_back(i);
			min_max_sum = max_sum;
		}
		else if (min_max_sum == max_sum) {
			answer.push_back(i);
		}
	}

	for (int x : answer) {
		cout << x << ' ';
	}
	cout << '\n';

	return 0;
}