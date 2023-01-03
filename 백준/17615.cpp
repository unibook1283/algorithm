#include <iostream>
#include <algorithm>
using namespace std;
int red = 0, blue = 0;
int cal_from_left(string balls) {
	char color = balls[0];
	int cont_cnt = 1;
	for (int i = 1; i < balls.size(); i++) {
		if (balls[i] == color) cont_cnt++;
		else break;
	}
	int ret;
	if (color == 'R') ret = red - cont_cnt;
	else ret = blue - cont_cnt;
	return ret;
}
int main() {
	int n;
	string balls;
	cin >> n >> balls;

	for (int i = 0; i < balls.size(); i++) {
		if (balls[i] == 'R') red++;
		else blue++;
	}
	if (red == 0 || blue == 0) {
		cout << 0 << '\n';
		return 0;
	}

	int ans = min(red, blue);
	ans = min(ans, cal_from_left(balls));
	reverse(balls.begin(), balls.end());
	ans = min(ans, cal_from_left(balls));
	cout << ans << '\n';

	return 0;
}