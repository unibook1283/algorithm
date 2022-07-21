#include <iostream>
#include <queue>
using namespace std;
struct cmp {
	bool operator() (int a, int b) {
		return a > b;
	}
};
int main() {
	int n;
	cin >> n;
	priority_queue<int, vector<int>, cmp> pq;
	while (n--) {
		int x;
		cin >> x;
		pq.push(x);
	}
	int ans = 0;
	while (pq.size() >= 2) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		ans += a + b;
		pq.push(a + b);
	}
	cout << ans << '\n';



	return 0;
}