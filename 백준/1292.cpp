#include <iostream>
#include <vector>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	vector<int> v;
	for (int i = 1; i <= 50; i++) {
		for (int j = 0; j < i; j++) {
			v.push_back(i);
		}
	}
	int ans = 0;
	for (int i = a - 1; i < b; i++) {
		ans += v[i];
	}
	cout << ans << '\n';

	return 0;
}