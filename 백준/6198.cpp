#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int a[80001];
struct cmp {
	bool operator() (int a, int b) {
		return a > b;
	}
};
int main() {
	int n;
	cin >> n;
	priority_queue<int, vector<int>, cmp> pq;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		while (!pq.empty() && pq.top() <= x) {
			pq.pop();
		}
		ans += pq.size();
		pq.push(x);
	}
	cout << ans << '\n';

	return 0;
}