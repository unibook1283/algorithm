#include <iostream>
#include <queue>
#include <set>
using namespace std;
int dx[] = { 1,-1, };
set<int> s;
long long bfs(queue<int> q, int k) {
	int count = 0;
	long long unhappiness = 0;
	int dist = 1;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int x = q.front();
			q.pop();
			for (int j = 0; j < 2; j++) {
				int nx = x + dx[j];
				if (s.find(nx) == s.end()) {
					s.insert(nx);
					count++;
					unhappiness += dist;
					q.push(nx);
				}
				if (count == k) return unhappiness;
			}
		}
		dist++;
	}
	return -1;
}
int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push(x);
		s.insert(x);
	}
	cout << bfs(q, k) << '\n';

	return 0;
}