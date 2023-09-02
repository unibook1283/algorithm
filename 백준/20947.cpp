#include <iostream>
using namespace std;
char map[2001][2001];
bool check[2001][2001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n;
void mark_cross(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x;
		int ny = y;
		while (1) {
			nx += dx[i];
			ny += dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
			if (map[nx][ny] != '.') break;
			check[nx][ny] = true;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (map[i][j] == 'O')
				mark_cross(i, j);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '.' && !check[i][j])
				cout << 'B';
			else
				cout << map[i][j];
		}
		cout << '\n';
	}

	return 0;
}