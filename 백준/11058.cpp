#include <iostream>
using namespace std;
long long d[101];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		for (int j = 3; j <= i; j++) {
			d[i] = max(d[i], d[i - j] * (j - 1));
		}
	}
	cout << d[n];

	return 0;
}
/*
재귀로는 시간안에 못할 듯. 4^100?
*/