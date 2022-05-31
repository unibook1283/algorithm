#include <iostream>
using namespace std;
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int x = 0, y = 0;
		int direction = 0;
		int minx = 0, maxx = 0, miny = 0, maxy = 0;
		for (char ch : s) {
			if (ch == 'F') {
				x += dx[direction];
				y += dy[direction];
			}
			else if (ch == 'B') {
				x -= dx[direction];
				y -= dy[direction];
			}
			else if (ch == 'L') {
				direction++;
				direction %= 4;
			}
			else if (ch == 'R') {
				direction--;
				if (direction == -1) direction = 3;
			}
			minx = min(minx, x);
			maxx = max(maxx, x);
			miny = min(miny, y);
			maxy = max(maxy, y);
		}
		cout << (maxx - minx) * (maxy - miny) << '\n';
	}

	return 0;
}