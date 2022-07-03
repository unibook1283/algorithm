#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Point {
	int x, y;
};
bool cmp(const Point& u, const Point& v) {
	if (u.y < v.y) {
		return true;
	}
	else if (u.y == v.y) {
		return u.x < v.x;
	}
	else {
		return false;
	}
}
int main() {
	int n;
	cin >> n;
	vector<Point> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y;
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << v[i].x << ' ' << v[i].y << '\n';
	}

	return 0;
}