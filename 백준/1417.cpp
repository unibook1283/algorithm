#include <iostream>
#include <queue>
using namespace std;
int main() {
	int n, dasom;
	cin >> n;
	cin >> dasom;
	n--;
	priority_queue<int> pq;
	while (n--) {
		int num;
		cin >> num;
		if (dasom <= num) {
			pq.push(num);
		}
	}
	int ans = 0;
	while (!pq.empty() && pq.top() >= dasom) {
		int top = pq.top();
		pq.pop();
		dasom++; top--;
		pq.push(top);
		ans++;
	}
	cout << ans << '\n';

	return 0;
}