#include <iostream>
using namespace std;
int a[8][8];
int kx, ky, sx, sy, n;
int dx[] = { 1,-1,0,0,1,-1,1,-1 };
int dy[] = { 0,0,-1,1,1,1,-1,-1 };
void move(int dir) {
	int nkx, nky, nsx, nsy;

	nkx = kx + dx[dir];
	nky = ky + dy[dir];
	if (nkx < 0 || nkx >= 8 || nky < 0 || nky >= 8) return;
	if (nkx == sx && nky == sy) {
		nsx = sx + dx[dir];
		nsy = sy + dy[dir];
		if (nsx < 0 || nsx >= 8 || nsy < 0 || nsy >= 8) return;
		sx = nsx; sy = nsy;
	}
	kx = nkx; ky = nky;
}
int main() {
	char kxc, sxc;

	cin >> kxc >> ky >> sxc >> sy >> n;
	kx = kxc - 'A';
	sx = sxc - 'A';
	ky--; sy--;

	for (int i = 0; i < n; i++) {
		int nkx, nky, nsx ,nsy;
		string op;
		cin >> op;
		if (op == "R") {
			move(0);
		}
		else if (op == "L") {
			move(1);
		}
		else if (op == "B") {
			move(2);
		}
		else if (op == "T") {
			move(3);
		}
		else if (op == "RT") {
			move(4);
		}
		else if (op == "LT") {
			move(5);
		}
		else if (op == "RB") {
			move(6);
		}
		else if (op == "LB") {
			move(7);
		}
	}
	cout << (char)(kx + 'A') << ky + 1 << '\n';
	cout << (char)(sx + 'A') << sy + 1 << '\n';

	return 0;
}