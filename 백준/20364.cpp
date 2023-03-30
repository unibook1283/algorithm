#include <iostream>
using namespace std;
bool check[1048577];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	while (q--) {
		int x;
		cin >> x;
		int firstMet = -1;
		int temp = x;
		while (temp) {
			if (check[temp]) {
				firstMet = temp;
			}
			temp /= 2;
		}
		check[x] = true;
		cout << (firstMet == -1 ? 0 : firstMet) << '\n';
	}

	return 0;
}