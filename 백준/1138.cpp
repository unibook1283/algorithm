#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n), res(n);
	vector<bool> check(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (!check[j]) {
				if (cnt == v[i]) {
					res[j] = i + 1;
					check[j] = true;
					break;
				}
				else cnt++;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';

	return 0;
}