#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int r, c;
char a[100][100];
int check[100][100];
// �� �鸰�� 0
// �鸰�� �� �ٴڿ� �پ��ִ°� 1
// �� �پ��ִ°� 2
vector<pair<int, int>> cluster;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
void throw_stick(int stick, int direction) {	//direction: 0 = �� -> ��	1 = �� -> ��
	if (direction == 0) {
		int x = 0;
		while (x < c) {
			if (a[stick][x] == 'x') {
				a[stick][x] = '.';
				break;
			}
			x++;
		}
	}
	else {
		int x = c - 1;
		while (x >= 0) {
			if (a[stick][x] == 'x') {
				a[stick][x] = '.';
				break;
			}
			x--;
		}
	}
}
void bfs(int x, int y) {
	bool on_floor = false;
	if (x == r - 1) on_floor = true;
	if (on_floor) {
		check[x][y] = 1;
	}
	else {
		check[x][y] = 2;
	}
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (!on_floor) cluster.push_back(make_pair(x, y));
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
				if (a[nx][ny] == 'x' && check[nx][ny] == 0) {
					if (on_floor) {
						check[nx][ny] = 1;
					}
					else {
						check[nx][ny] = 2;
					}
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
void gravity() {
	int min_height = 101;
	for (int i = 0; i < cluster.size(); i++) {
		int height = 0;
		int x = cluster[i].first;
		int y = cluster[i].second;
		while (1) {
			height++;
			if (x + height >= r || check[x + height][y] == 1) {
				min_height = min(min_height, height - 1);
				break;
			}
		}
	}
	for (int i = r - 1; i >= 0; i--) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] == 'x' && check[i][j] == 2) {
				a[i][j] = '.';
				a[i + min_height][j] = 'x';

			}
		}
	}
}
int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		memset(check, 0, sizeof(check));
		int stick;
		cin >> stick;
		stick = r - stick;
		throw_stick(stick, i % 2);

		for (int i = r - 1; i >= 0; i--) {
			for (int j = 0; j < c; j++) {
				if (a[i][j] == 'x' && check[i][j] == 0) {
					bfs(i, j);
					
				}
			}
		}
		if (!cluster.empty()) {
			gravity();
			cluster.clear();
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << a[i][j];
		}
		cout << '\n';
	}

	return 0;
}
/*
stick �� �� ������, ���߿� ���ִ� cluster�� 2�� �̻� ���� �� �ִ°�? Yes.
ex)
..x.
..x.
xxx.<-
..x.
..x.

��, ������ "�� �� �Ǵ� �� �̻��� Ŭ�����Ͱ� ���ÿ� �������� ��쵵 ����."
������ �ֳ�...
*/