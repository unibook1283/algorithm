#include <iostream>
#include <set>
#include <queue>
using namespace std;
bool check[201][201][201];
set<int> bfs(int a, int b, int c) {
	set<int> answer;
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0,{0,c} });
	check[0][0][c] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second.first;
		int z = q.front().second.second;
		q.pop();
		if (x == 0) answer.insert(z);
		if (x > 0) {
			int nx = x - min(x, b - y);
			int ny = y + min(x, b - y);
			if (!check[nx][ny][z]) {
				check[nx][ny][z] = true;
				q.push({ nx,{ny,z} });
			}
			nx = x - min(x, c - z);
			int nz = z + min(x, c - z);
			if (!check[nx][y][nz]) {
				check[nx][y][nz] = true;
				q.push({ nx,{y,nz} });
			}
		}
		if (y > 0) {
			int ny = y - min(y, a - x);
			int nx = x + min(y, a - x);
			if (!check[nx][ny][z]) {
				check[nx][ny][z] = true;
				q.push({ nx,{ny,z} });
			}
			ny = y - min(y, c - z);
			int nz = z + min(y, c - z);
			if (!check[x][ny][nz]) {
				check[x][ny][nz] = true;
				q.push({ x,{ny,nz} });
			}
		}
		if (z > 0) {
			int nz = z - min(z, a - x);
			int nx = x + min(z, a - x);
			if (!check[nx][y][nz]) {
				check[nx][y][nz] = true;
				q.push({ nx,{y,nz} });
			}
			nz = z - min(z, b - y);
			int ny = y + min(z, b - y);
			if (!check[x][ny][nz]) {
				check[x][ny][nz] = true;
				q.push({ x,{ny,nz} });
			}
		}
	}
	return answer;
}
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	set<int> answer = bfs(a, b, c);
	for (int x : answer) {
		cout << x << ' ';
	}
	cout << '\n';

	return 0;
}