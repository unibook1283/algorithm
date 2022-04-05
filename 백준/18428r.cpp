#include <iostream>
#include <vector>
using namespace std;
char a[6][6];
vector<pair<int, int>> x, t;
int n;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool can_avoid() {
	for (int i = 0; i < t.size(); i++) {
		int tx = t[i].first;
		int ty = t[i].second;
		for (int j = 0; j < 4; j++) {
			int nx = tx;
			int ny = ty;
			while (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (a[nx][ny] == 'S') return false;
				if (a[nx][ny] == 'O') break;
				nx += dx[j];
				ny += dy[j];
			}
		}
	}
	return true;
}
void go(int cnt, int index) {
	if (cnt == 3) {		// 3개를 정한 경우
		if (!can_avoid()) {
			return;
		}
		cout << "YES";
		exit(0);
	}
	/*
	if (index == x.size()) {	// 다 돌았는데 3개를 못 정한 경우를 처리 안해줘도 되네?

	}
	*/
	for (int i = index; i < x.size(); i++) {
		a[x[i].first][x[i].second] = 'O';
		go(cnt + 1, i + 1);
		a[x[i].first][x[i].second] = 'X';
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'T') {
				t.push_back(make_pair(i, j));
			}
			if (a[i][j] == 'X') {
				x.push_back(make_pair(i,j));
			}
		}
	}
	go(0, 0);
	cout << "NO";

	return 0;
}
/*
완전히 이해되지 않은 부분들이 있음.
다음에 꼭 다시 풀어볼 문제. 배운것도 많았음.
1. while (nx >= 0 && nx < n && ny >= 0 && ny < n)
2. 이런 상황에 재귀 쓰는것.
3. exit 쓰는것.
*/