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
	if (cnt == 3) {		// 3���� ���� ���
		if (!can_avoid()) {
			return;
		}
		cout << "YES";
		exit(0);
	}
	/*
	if (index == x.size()) {	// �� ���Ҵµ� 3���� �� ���� ��츦 ó�� �����൵ �ǳ�?

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
������ ���ص��� ���� �κе��� ����.
������ �� �ٽ� Ǯ� ����. ���͵� ������.
1. while (nx >= 0 && nx < n && ny >= 0 && ny < n)
2. �̷� ��Ȳ�� ��� ���°�.
3. exit ���°�.
*/