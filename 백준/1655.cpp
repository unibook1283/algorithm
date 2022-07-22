#include <iostream>
#include <queue>
using namespace std;
struct cmp {
	bool operator() (int a, int b) {
		return a > b;
	}
};
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	priority_queue<int> left;
	priority_queue<int, vector<int>, cmp> right;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (left.size() > right.size()) right.push(x);
		else left.push(x);
		if (!left.empty() && !right.empty()) {
			int a = left.top();
			int b = right.top();
			if (a > b) {
				left.pop();
				right.pop();
				left.push(b);
				right.push(a);
			}
		}
		cout << left.top() << '\n';
	}

	return 0;
}