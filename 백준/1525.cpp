#include <iostream>
#include <cstring>
#include <queue>
#include <set>
#include <algorithm>
#include <tuple>
using namespace std;
set<string> check;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int bfs(string s) {
	check.insert(s);
	int zero = s.find('0');

	queue<pair<string, int>> q;	// <표 상황, 이동 횟수>
	q.push(make_pair(s, 0));
	while (!q.empty()) {
		s = q.front().first;
		int d = q.front().second;
		q.pop();
		//cout << s << '\n';
		if (s == "123456780") return d;
		zero = s.find('0');
		int x = zero / 3;
		int y = zero % 3;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int zero_to = 3 * nx + ny;
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
				if (check.find(s) != check.end()) {
					string next = s;
					swap(next[zero], next[zero_to]);
					if (check.find(next) == check.end()) {
						check.insert(next);
						q.push(make_pair(next, d + 1));
					}
				}
			}
		}
	}
	return -1;
}
int main() {
	string s;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			char ch;
			cin >> ch;
			s.push_back(ch);
		}
	}
	cout << bfs(s) << '\n';

	return 0;
}