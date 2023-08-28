#include <iostream>
using namespace std;
int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	int length;
	int x3, y3, x4, y4;
	if (x1 == x2) {
		length = abs(y2 - y1);
		x3 = x1 + length;
		x4 = x3;
		y3 = y1;
		y4 = y2;
	}
	else if (y1 == y2) {
		length = abs(x2 - x1);
		y3 = y1 + length;
		y4 = y3;
		x3 = x1;
		x4 = x2;
	}
	else {
		if (abs(x2 - x1) != abs(y2 - y1)) {
			cout << -1 << '\n';
			return 0;
		}
		x3 = x1;
		y3 = y2;
		x4 = x2;
		y4 = y1;
	}
	cout << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << '\n';

	return 0;
}