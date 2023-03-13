#include <iostream>
using namespace std;
int a[1000001];
int n;
void switchThreeFromHere(int index) {
	for (int i = 0; i < 3; i++)
		if (index + i < n)
			a[index + i] = !a[index + i];
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			switchThreeFromHere(i);
			ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}