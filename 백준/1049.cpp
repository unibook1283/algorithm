#include <iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int six = 1000, one = 1000;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		six = min(six, a);
		one = min(one, b);
	}
	cout << min(n * one, min(n / 6 * six + n % 6 * one, (n / 6 + 1) * six)) << '\n';




	return 0;
}