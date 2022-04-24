#include <iostream>
using namespace std;
long long f[117];
int main() {
	int n;
	cin >> n;
	f[1] = f[2] = f[3] = 1;
	for (int i = 4; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 3];
	}
	cout << f[n] << '\n';
	return 0;
}