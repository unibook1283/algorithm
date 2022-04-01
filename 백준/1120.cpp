#include <iostream>
#include <string>
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	int al = a.length();
	int bl = b.length();
	int ans = 987654321;
	for (int i = 0; i <= bl - al; i++) {
		int dif = 0;
		for (int j = 0; j < al; j++) {
			if (a[j] != b[i + j]) dif++;
		}
		ans = min(ans, dif);
	}
	cout << ans;

	return 0;
}