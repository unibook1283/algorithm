#include <iostream>
#include <vector>
#include <limits>
using namespace std;
const int MIN_INT = numeric_limits<int>::min();
const int MAX_INT = numeric_limits<int>::max();
struct RMQ {
	int n;
	vector<pair<int, int>> minMaxArray;
	RMQ(vector<int>& array) {
		n = array.size();
		minMaxArray.resize(n * 4);
		init(array, 0, n - 1, 1);
	}
	pair<int, int> init(vector<int>& array, int left, int right, int node) {
		if (left == right)
			return minMaxArray[node] = { array[left], array[left] };
		int mid = (left + right) / 2;
		return minMaxArray[node] = get_min_max_pair(
			init(array, left, mid, 2 * node),
			init(array, mid + 1, right, 2 * node + 1)
		);
	}
	pair<int, int> query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || nodeRight < left)
			return { MAX_INT, MIN_INT };
		if (left <= nodeLeft && nodeRight <= right)
			return minMaxArray[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return get_min_max_pair(
			query(left, right, 2 * node, nodeLeft, mid),
			query(left, right, 2 * node + 1, mid + 1, nodeRight)
		);
	}
	int query(int left, int right) {
		pair<int, int> min_max_pair = query(left, right, 1, 0, n - 1);
		return min_max_pair.second - min_max_pair.first;
	}
	pair<int, int> get_min_max_pair(pair<int, int> a, pair<int, int> b) {
		return { min(a.first, b.first), max(a.second, b.second) };
	}
};
int main() {
	int c;
	cin >> c;
	while (c--) {
		int n, q;
		cin >> n >> q;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		RMQ rmq(v);
		while (q--) {
			int a, b;
			cin >> a >> b;
			cout << rmq.query(a, b) << '\n';
		}
	}

	return 0;
}