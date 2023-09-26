#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
vector<int> arr;
struct SegmentTree {
	int n;
	vector<int> rangeMin;
	SegmentTree() {
		n = arr.size();
		rangeMin.resize(4 * n);
		init(0, n - 1, 1);
	}
	int init(int left, int right, int node) {
		if (left == right)
			return rangeMin[node] = arr[left];
		int mid = (left + right) / 2;
		return rangeMin[node] = min(
			init(left, mid, node * 2),
			init(mid + 1, right, node * 2 + 1)
		);
	}
	int query(int left, int right) {
		return query(left, right, 1, 0, n - 1);
	}
	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (nodeRight < left || right < nodeLeft)
			return INT_MAX;
		if (left <= nodeLeft && nodeRight <= right)
			return rangeMin[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return min(
			query(left, right, node * 2, nodeLeft, mid),
			query(left, right, node * 2 + 1, mid + 1, nodeRight)
		);
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	SegmentTree st;
	while (m--) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		cout << st.query(a, b) << '\n';
	}

	return 0;
}