#include <iostream>
#include <deque>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, l;
	cin >> n >> l;
	deque<pair<int, int>> deq;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (!deq.empty() && deq.front().second < i - l + 1) deq.pop_front();
		while (!deq.empty() && deq.back().first >= a) deq.pop_back();
		deq.push_back({ a, i });
		cout << deq.front().first << ' ';
	}
	cout << '\n';

	return 0;
}