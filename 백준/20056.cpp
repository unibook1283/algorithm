#include <iostream>
#include <vector>
using namespace std;
struct fire {
	int x, y, m, s, d;
};
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };
vector<fire> fires;
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int x, y, m, s, d;
		cin >> x >> y >> m >> s >> d;
		x--; y--;
		fire f;
		f.x = x;
		f.y = y;
		f.m = m;
		f.s = s;
		f.d = d;
		fires.push_back(f);
	}

	while (k--) {
		vector<fire> v[51][51];
		for (int i = 0; i < fires.size(); i++) {
			fire f = fires[i];
			int x_dir = dx[f.d];
			int y_dir = dy[f.d];
			int nx = f.x + x_dir * (f.s % n);
			int ny = f.y + y_dir * (f.s % n);
			nx = (nx + n) % n; ny = (ny + n) % n;
			f.x = nx; f.y = ny;
			v[nx][ny].push_back(f);
		}
		fires.clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j].size() >= 2) {
					int combined_m = 0, combined_s = 0;
					bool odd = true, even = true;
					int size = v[i][j].size();
					for (int l = 0; l < v[i][j].size();) {
						fire f = v[i][j][l];
						v[i][j].erase(v[i][j].begin() + l);
						combined_m += f.m;
						combined_s += f.s;
						if (f.d % 2 == 0) odd = false;
						else even = false;
					}
					combined_m /= 5;
					combined_s /= size;
					if (combined_m == 0) continue;
					int plus;
					if (odd || even) {
						plus = 0;
					}
					else {
						plus = 1;
					}
					for (int k = 0; k < 8; k += 2) {
						fire f;
						f.x = i;
						f.y = j;
						f.m = combined_m;
						f.s = combined_s;
						f.d = k + plus;
						fires.push_back(f);
					}
				}
				else if (v[i][j].size() == 1) {
					fires.push_back(v[i][j][0]);
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < fires.size(); i++) {
		ans += fires[i].m;
	}
	cout << ans << '\n';

	return 0;
}