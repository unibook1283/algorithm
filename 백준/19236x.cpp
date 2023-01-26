#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Fish {
	int x, y;
	int id;	// ¸ÔÈù°Ç -1
	int dir;
};
struct Shark {
	int x, y;
	int dir;
};
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,-1,-1,-1,0,1,1,1 };
int ans = 0;
bool cmp(Fish a, Fish b) {
	return a.id < b.id;
}
int find_fish_by_xy(vector<Fish> fishes, int x, int y) {
	for (int i = 0; i < fishes.size(); i++) {
		if (fishes[i].x == x && fishes[i].y == y)
			return i;
	}
	return -1;
}
void move_fishes(vector<Fish>& fishes, Shark shark) {
	for (int i = 0; i < fishes.size(); i++) {
		Fish& fish = fishes[i];
		if (fish.id == -1) continue;
		int initial_dir = fish.dir;
		while (1) {
			int dir = fish.dir;
			int nx = fish.x + dx[dir];
			int ny = fish.y + dy[dir];
			if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
				if (nx != shark.x || ny != shark.y) {
					int next = find_fish_by_xy(fishes, nx, ny);
					if (next != -1) {
						fishes[next].x = fish.x;
						fishes[next].y = fish.y;
					}
					fish.x = nx;
					fish.y = ny;
					break;
				}
			}
			fish.dir = (dir + 1) % 8;
			if (fish.dir == initial_dir) break;
		}
	}
}
void go(vector<Fish> fishes, Shark shark, int sum) {
	int eaten_fish_index = find_fish_by_xy(fishes, shark.x, shark.y);
	Fish& eaten = fishes[eaten_fish_index];
	if (eaten.id != -1) {
		sum += eaten.id;
		eaten.id = -1;
		shark.dir = eaten.dir;
	}
	ans = max(ans, sum);
	move_fishes(fishes, shark);

	int dir = shark.dir;
	while (1) {
		shark.x = shark.x + dx[dir];
		shark.y = shark.y + dy[dir];
		if (shark.x < 0 || shark.x >= 4 || shark.y < 0 || shark.y >= 4) break;
		if (find_fish_by_xy(fishes, shark.x, shark.y) == -1) continue;
		go(fishes, shark, sum);
	}
}
int main() {
	vector<Fish> fishes;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			b--;
			Fish fish = { i, j, a, b };
			fishes.push_back(fish);
		}
	}
	sort(fishes.begin(), fishes.end(), cmp);
	Shark shark = { 0,0,-1 };
	go(fishes, shark, 0);
	cout << ans << '\n';

	return 0;
}