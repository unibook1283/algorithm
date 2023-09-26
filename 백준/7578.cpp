#include <iostream>
#include <limits.h>
using namespace std;
int a[500001];
int b[1000001];
int tree[500001 * 4];
long long query(int left, int right, int node, int nodeLeft, int nodeRight) {
	if (nodeRight < left || right < nodeLeft)
		return 0;
	if (left <= nodeLeft && nodeRight <= right)
		return tree[node];
	int mid = (nodeLeft + nodeRight) / 2;
	return query(left, right, node * 2, nodeLeft, mid)
		+ query(left, right, node * 2 + 1, mid + 1, nodeRight);
}
int update(int index, int nodeLeft, int nodeRight, int node) {
	if (index < nodeLeft || nodeRight < index)
		return tree[node];
	if (nodeLeft == nodeRight)
		return tree[node] = 1;
	int mid = (nodeLeft + nodeRight) / 2;
	return tree[node] = update(index, nodeLeft, mid, node * 2)
		+ update(index, mid + 1, nodeRight, node * 2 + 1);
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		b[x] = i;
	}

	long long answer = 0;
	for (int i = 0; i < n; i++) {
		int b_index = b[a[i]];
		answer += query(b_index + 1, n - 1, 1, 0, n - 1);
		update(b_index, 0, n - 1, 1);
	}
	cout << answer << '\n';

	return 0;
}