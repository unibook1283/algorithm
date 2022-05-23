#include <iostream>
using namespace std;
string keyboard[3] = {
	"qwertyuiop", "asdfghjkl", "zxcvbnm"
};
string left_k = "qwertasdfgzxcv";
int cal_dis(char a, char b) {
	int ax, ay, bx, by;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < keyboard[i].size(); j++) {
			if (a == keyboard[i][j]) {
				ax = i; ay = j;
			}
			if (b == keyboard[i][j]) {
				bx = i; by = j;
			}
		}
	}
	int dx = ax - bx;
	if (dx < 0)dx = -dx;
	int dy = ay - by;
	if (dy < 0)dy = -dy;
	return dx + dy;
}
int main() {
	char sl, sr;
	cin >> sl >> sr;
	string s;
	cin >> s;
	
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (left_k.find(s[i]) != string::npos) {
			ans += cal_dis(sl, s[i]);
			sl = s[i];
		}
		else {
			ans += cal_dis(sr, s[i]);
			sr = s[i];
		}
	}
	
	ans += s.size();

	cout << ans << '\n';

	return 0;
}