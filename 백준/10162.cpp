#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	if (t % 10 != 0) {
		cout << -1;
		return 0;
	}
	int a, b, c;
	a = t / 300;
	t %= 300;
	b = t / 60;
	t %= 60;
	c = t / 10;
	cout << a << ' ' << b << ' ' << c;

	return 0;
}