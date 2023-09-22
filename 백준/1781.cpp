#include <iostream>
#include <queue>
using namespace std;
int parent[200001];
int get_parent(int x) {
	if (x == -1) return -1;
	if (x == parent[x]) return x;
	return parent[x] = get_parent(parent[x]);
}
void union_parent(int x, int y) {
	x = get_parent(x);
	y = get_parent(y);
	if (x == -1) parent[y] = -1;
	else if (y == -1) parent[x] = -1;
	else if (x < y) parent[y] = x;
	else parent[x] = y;
}
int main() {
	int n;
	cin >> n;
	priority_queue<pair<int, int>> pq;	// (ÄÅ¶ó¸é ¼ö, deadline)
	for (int i = 0; i < n; i++) {
		int deadline, cup;
		cin >> deadline >> cup;
		deadline--;
		pq.push({ cup, deadline });
		parent[i] = i;
	}
	
	int answer = 0;
	while (!pq.empty()) {
		int cup = pq.top().first;
		int deadline = pq.top().second;
		pq.pop();
		int p = get_parent(deadline);
		if (p != -1) {
			answer += cup;
			union_parent(p, p - 1);
		}
	}
	cout << answer << '\n';
	
	return 0;
}