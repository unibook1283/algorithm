#include <iostream>
#include <vector>
using namespace std;
const int MAX = 12;
const int CHESS_MAX = 10;
int map[MAX][MAX];
vector<int> map_state[MAX][MAX];
int n, k;
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };
int rdir[] = { 0,2,1,4,3 };
typedef struct Chess{
	int x;
	int y;
	int dir;
	bool at_bottom;
};
Chess chess[CHESS_MAX];
bool check_state() {
	for (int i = 0; i < k; i++) {
		int x = chess[i].x;
		int y = chess[i].y;
		if (map_state[x][y].size() >= 4) return true;
	}
	return false;
}
void change_state(int x, int y, int nx, int ny) {
	int color = 2;
	if (nx >= 0 && nx < n && ny >= 0 && ny < n)
		color = map[nx][ny];
	if (color == 0) {
		if (!map_state[nx][ny].empty())
			chess[map_state[x][y][0]].at_bottom = false;
		for (int i = 0; i < map_state[x][y].size(); i++) {
			map_state[nx][ny].push_back(map_state[x][y][i]);
			chess[map_state[x][y][i]].x = nx;
			chess[map_state[x][y][i]].y = ny;
		}
		map_state[x][y].clear();
	}
	else if (color == 1) {
		chess[map_state[x][y][0]].at_bottom = false;
		if (map_state[nx][ny].empty())
			chess[map_state[x][y].back()].at_bottom = true;
		for (int i = map_state[x][y].size() - 1; i >= 0; i--) {
			map_state[nx][ny].push_back(map_state[x][y][i]);
			chess[map_state[x][y][i]].x = nx;
			chess[map_state[x][y][i]].y = ny;
		}
		map_state[x][y].clear();
	}
	else {
		int dir = rdir[chess[map_state[x][y][0]].dir];
		chess[map_state[x][y][0]].dir = dir;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (map[nx][ny] != 2)
				change_state(x, y, nx, ny);
		}
	}
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int x, y, dir;
		cin >> x >> y >> dir;
		x--; y--;
		chess[i] = { x,y,dir,true };
		map_state[x][y].push_back(i);
	}

	bool flag = false;
	int turn = 0;
	while (1) {
		if (check_state()) {
			flag = true;
			break;
		}
		if (turn > 1000) break;
		for (int i = 0; i < k; i++) {
			if (!chess[i].at_bottom) continue;
			int x = chess[i].x;
			int y = chess[i].y;
			int dir = chess[i].dir;

			int nx = x + dx[dir];
			int ny = y + dy[dir];
			change_state(x, y, nx, ny);
		}
		turn++;
	}
	if (flag) cout << turn << '\n';
	else cout << "-1\n";

	return 0;
}