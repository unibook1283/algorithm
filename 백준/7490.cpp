#include <iostream>
using namespace std;
int N;
void go(int n, int sum, int sign, int num, string str) {
	if (n == N) {
		sum += num * sign;
		if (sum==0)
			cout << str << '\n';
		return;
	}
	go(n + 1, sum, sign, num * 10 + n + 1, str + ' ' + char(n + 1 + '0'));
	go(n + 1, sum + sign * num, 1, n + 1, str + '+' + char(n + 1 + '0'));
	go(n + 1, sum + sign * num, -1, n + 1, str + '-' + char(n + 1 + '0'));
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> N;
		go(1, 0, 1, 1, "1");
		cout << '\n';
	}

	return 0;
}