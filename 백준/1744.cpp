#include <iostream>
#include <queue>
using namespace std;
int a[51];
int main() {
	priority_queue<int> negative, positive;
	int n, zero = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x < 0) negative.push(-x);
		else if (x == 0) zero++;
		else positive.push(x);
	}
	
	int ans = 0;
	while (negative.size() >= 2) {
		int a = negative.top(); negative.pop();
		int b = negative.top(); negative.pop();
		ans += a * b;
	}
	while (positive.size() >= 2) {
		int a = positive.top(); positive.pop();
		int b = positive.top(); positive.pop();
		if (b == 1) ans += a + b;
		else ans += a * b;
	}

	if (!negative.empty())
		if (zero == 0) ans -= negative.top();
	if (!positive.empty())
		ans += positive.top();

	cout << ans << '\n';

	return 0;
}