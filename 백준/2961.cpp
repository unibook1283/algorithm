#include <iostream>
#include <vector>
using namespace std;
int a[10];
int b[10];
int cnt;
int n;
int ans = 987654321;
void go(int sour, int bitter, int index) {
	if (index == n) {
		if (sour == 1 && bitter == 0) return;
		int dif = bitter - sour;
		if (dif < 0) dif = -dif;
		ans = min(ans, dif);
		return;
	}
	go(sour * a[index], bitter + b[index], index + 1);
	go(sour, bitter, index + 1);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	go(1, 0, 0);
	cout << ans;


	return 0;
}