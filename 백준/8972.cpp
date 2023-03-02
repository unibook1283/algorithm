#include <iostream>
#include <vector>
using namespace std;
int n, m;
char a[101][101];
vector<int> idsOnCoord[101][101];
int dx[] = { 1,1,1,0,0,0,-1,-1,-1 };
int dy[] = { -1,0,1,-1,0,1,-1,0,1 };
struct MadArduino {
	int id;
	int x, y;
	bool exploded;
};
void explodeMadArduino(vector<MadArduino>& madArduinos, int id) {
	for (int i = 0; i < madArduinos.size(); i++) {
		if (madArduinos[i].id == id) {
			madArduinos[i].exploded = true;
			break;
		}
	}
}
void printMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j];
		}
		cout << '\n';
	}
}
void eraseOne(int x, int y, int id) {
	for (int i = 0; i < idsOnCoord[x][y].size(); i++) {
		if (idsOnCoord[x][y][i] == id) {
			idsOnCoord[x][y].erase(idsOnCoord[x][y].begin() + i);
			break;
		}
	}
}
int main() {
	cin >> n >> m;
	int sx, sy;
	vector<MadArduino> madArduinos;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'I') {
				sx = i;
				sy = j;
			}
			else if (a[i][j] == 'R') {
				idsOnCoord[i][j].push_back(cnt);

				MadArduino ma;
				ma.id = cnt++;
				ma.x = i;
				ma.y = j;
				ma.exploded = false;
				madArduinos.push_back(ma);
			}
		}
	}
	string cmds;
	cin >> cmds;
	for (int i = 0; i < cmds.size(); i++) {
		// 종수 아두이노의 이동
		int dir = cmds[i] - '1';
		a[sx][sy] = '.';
		sx += dx[dir];
		sy += dy[dir];
		a[sx][sy] = 'I';

		// 끝
		if (!idsOnCoord[sx][sy].empty()) {
			cout << "kraj " << i + 1 << '\n';
			return 0;
		}

		// 미친 아두이노의 이동
		for (int j = 0; j < madArduinos.size(); j++) {
			MadArduino& ma = madArduinos[j];
			if (ma.exploded) continue;
			int nx = ma.x, ny = ma.y;
			if (nx > sx) {
				nx--;
			}
			else if (nx < sx) {
				nx++;
			}
			if (ny > sy) {
				ny--;
			}
			else if (ny < sy) {
				ny++;
			}
			eraseOne(ma.x, ma.y, ma.id);
			idsOnCoord[nx][ny].push_back(ma.id);
			if (idsOnCoord[ma.x][ma.y].empty())
				a[ma.x][ma.y] = '.';
			a[nx][ny] = 'R';
			ma.x = nx;
			ma.y = ny;			
		}

		// 폭파
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < m; col++) {
				if (idsOnCoord[row][col].size() >= 1) {
					if (row == sx && col == sy) {
						// 끝
						cout << "kraj " << i + 1 << '\n';
						return 0;
					}
					if (idsOnCoord[row][col].size() > 1) {
						for (int j = 0; j < idsOnCoord[row][col].size(); j++) {
							int id = idsOnCoord[row][col][j];
							explodeMadArduino(madArduinos, id);
						}
						a[row][col] = '.';
						idsOnCoord[row][col].clear();
					}
				}
			}
		}
	}
	printMap();

	return 0;
}