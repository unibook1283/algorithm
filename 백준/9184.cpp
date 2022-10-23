#include <iostream>
#include <cstring>
using namespace std;
int w[21][21][21];
int go(int a, int b, int c) {
	if (a <= 0 or b <= 0 or c <= 0) return 1;
	else if (a > 20 or b > 20 or c > 20) {
		return go(20, 20, 20);
	}
	else if (w[a][b][c] != -1) return w[a][b][c];
	else if (a < b and b < c) {
		return w[a][b][c] = go(a, b, c - 1) + go(a, b - 1, c - 1) - go(a, b - 1, c);
	}
	else {
		return w[a][b][c] = go(a - 1, b, c) + go(a - 1, b - 1, c) + go(a - 1, b, c - 1) - go(a - 1, b - 1, c - 1);
	}
}
int main() {
	while (1) {
		memset(w, -1, sizeof(w));
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << go(a, b, c) << '\n';
	}

	return 0;
}