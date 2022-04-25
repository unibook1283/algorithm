#include <iostream>
using namespace std;
int n, d;
int cnt = 0;
void go(int num) {
	if (num == 0)return;
	if (d == num % 10) cnt++;
	go(num / 10);
}
int main() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		go(i);
	}
	cout << cnt << '\n';

	return 0;
}