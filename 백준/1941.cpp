#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
char a[5][5];
bool check[5][5];
vector<int> perm;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool bfs(int x, int y) {
	memset(check, false, sizeof(check));
	int s = 0, yy = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (s + yy == 7) {
			if (s > yy) {
				/*
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; j++) {
						cout << check[i][j];
					}
					cout << '\n';
				}
				cout << '\n';
				*/
				return true;
			}
			else return false;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
				if (perm[nx * 5 + ny] == 1 && check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
					if (a[nx][ny] == 'S') s++;
					else yy++;
				}
			}
		}
	}
	return false;
}
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 25 - 7; i++) {
		perm.push_back(0);
	}
	for (int i = 0; i < 7; i++) {
		perm.push_back(1);
	}
	int ans = 0;
	do {
		for (int i = 0; i < 25; i++) {	//for (int i = 0; i < 25 - 7; i++) { 에서 고침.	
			if (perm[i] == 1) {
				if (bfs(i / 5, i % 5)) {
					ans++;
				}
				break;
			}
		}
	} while (next_permutation(perm.begin(), perm.end()));
	cout << ans;

	return 0;
}
/*
반례:
SSSSS
SSSSS
SSSSS
SSSSS
SSSSS
답 : 3546
my : 3545
반례를 생각할 땐 극단적인걸 한 번 고려해보자.
for (int i = 0; i < 25 - 7; i++) {
얘가 i=18을 안돌아서 0000000000000000001111111을 안 셈.
*/