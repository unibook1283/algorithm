#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int N;
int a[100001];
struct SegmentTree {
	int n;
	vector<int> rangeMin;
	SegmentTree() {
		n = N;
		rangeMin.resize(n * 4);
		init(1, 0, n - 1);
	}
	int init(int node, int nodeLeft, int nodeRight) {
		if (nodeLeft == nodeRight)
			return rangeMin[node] = nodeLeft;
		int mid = (nodeLeft + nodeRight) / 2;
		return rangeMin[node] = minIndex(
			init(node * 2, nodeLeft, mid),
			init(node * 2 + 1, mid + 1, nodeRight)
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
		return minIndex(
			query(left, right, node * 2, nodeLeft, mid),
			query(left, right, node * 2 + 1, mid + 1, nodeRight)
		);
	}
	int minIndex(int x, int y) {
		// x, y 둘 다 INT_MAX일 수는 없다.
		if (x == INT_MAX) return y;
		else if (y == INT_MAX) return x;
		return a[x] < a[y] ? x : y;
	}
	int maxArea(int left, int right) {
		if (left > right) return -1;
		int mini = query(left, right);
		int ret = (right - left + 1) * a[mini];
		if (left <= mini - 1)
			ret = max(ret, maxArea(left, mini - 1));
		if (mini + 1 <= right)
			ret = max(ret, maxArea(mini + 1, right));
		return ret;
	}
};
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	SegmentTree st;
	cout << st.maxArea(0, N - 1) << '\n';

	return 0;
}