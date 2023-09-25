#include <cstdio>
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
vector<int> a;
struct SegmentTree {
	int n;
	vector<int> v;	// index
	SegmentTree(vector<int> array) {
		n = array.size();
		v.resize(4 * n);
		init(array, 1, 0, n - 1);
	}
	int init(vector<int> array, int node, int left, int right) {
		if (left == right)
			return v[node] = left;
		int mid = (left + right) / 2;
		return v[node] = minIndex(
			init(array, 2 * node, left, mid),
			init(array, 2 * node + 1, mid + 1, right)
		);
	}
	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (nodeRight < left || right < nodeLeft)
			return INT_MAX;
		if (left <= nodeLeft && right <= nodeRight)
			return v[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return minIndex(
			query(left, right, 2 * node, nodeLeft, mid),
			query(left, right, 2 * node + 1, mid + 1, nodeRight)
		);
	}
	int query(int left, int right) {
		return query(left, right, 1, 0, n - 1);
	}
	int update(int index, int value, int node, int nodeLeft, int nodeRight) {
		if (index < nodeLeft || nodeRight < index)
			return v[node];
		if (nodeLeft == nodeRight)
			return v[node] = nodeLeft;
		int mid = (nodeLeft + nodeRight) / 2;
		return v[node] = minIndex(
			update(index, value, 2 * node, nodeLeft, mid),
			update(index, value, 2 * node + 1, mid + 1, nodeRight)
		);
	}
	int update(int index, int value) {
		return update(index, value, 1, 0, n - 1);
	}
	int minIndex(int x, int y) {
		if (a[x] == a[y]) return x < y ? x : y;
		return a[x] < a[y] ? x : y;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	SegmentTree st(a);

	int m;
	cin >> m;

	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int index, value;
			cin >> index >> value;
			index--;
			a[index] = value;
			st.update(index, value);
		}
		else {
			cout << st.query(0, n - 1) + 1 << '\n';
		}
	}

	return 0;
}