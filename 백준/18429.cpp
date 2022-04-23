#include <iostream>
using namespace std;
int n, k;
int a[8];
bool check[8];
int ans = 0;
void go(int count, int weight) {
	if (count == n) {
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			check[i] = true;
			weight += a[i] - k;
			if (weight < 500) {
				check[i] = false;
				weight -= a[i] - k;
				continue;
			}
			go(count + 1, weight);
			check[i] = false;
			weight -= a[i] - k;
		}
	}
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	go(0, 500);

	cout << ans << '\n';



	return 0;
}
/*
next_permutation은 중복을 알아서 제거하는구나.
그래서 이 문제에선 못 씀.
*/