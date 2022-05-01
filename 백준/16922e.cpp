#include <iostream>
using namespace std;
int n;
int roma[4] = { 1,5,10,50 };
bool num[1001];
int ans = 0;
void go(int index, int d, int sum) {
	if (index == n) {
		if (!num[sum]) {
			num[sum] = true;
			ans++;
		}
		return;
	}
	for (int i = d; i < 4; i++) {
		go(index + 1, i, sum + roma[i]);
	}
}
int count() {
	int cnt = 0;
	for (int i = 0; i < 1001; i++) {
		if (num[i]) cnt++;
	}
	return cnt;
}
int main() {
	cin >> n;
	go(0, 0, 0);
	cout << count();

	return 0;
}
/*
중복조합
다시 풀어보면 좋을듯.
*/