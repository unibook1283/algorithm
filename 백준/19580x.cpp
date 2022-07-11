#include <iostream>
#include <queue>
using namespace std;
struct {
	long long l, r;
} money[500001];
struct {
	long long p;
	int x;
} mask[500001];
struct compare {
	bool operator()(pair<int, int> u, pair<int, int> v) {
		return u.first > v.first;
	}
};
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> money[i].l >> money[i].r;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;	// (속하는 범위의 개수, 시민의 index)
	for (int i = 0; i < m; i++) {
		cin >> mask[i].p >> mask[i].x;
	}
	
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			if (money[i].l <= mask[j].p && mask[j].p <= money[i].r) {
				cnt++;
			}
		}
		pq.push(make_pair(cnt, i));
	}

	int ans = 0;
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		int index = p.second;
		long long left = money[index].l;
		long long right = money[index].r;
		for (int i = 0; i < m; i++) {
			if (mask[i].x != 0 &&
				left <= mask[i].p &&
				mask[i].p <= right) {
				ans++;
				mask[i].x--;
				continue;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
/*
시간복잡도 O(nm)으로 시간초과 나오는구나.
배운 것 : algorihtm의 sort()는 개선된 quick sort 알고리즘으로,
어떠한 경우에서도 O(n*logn)을 만족한다.
(원래 quick sort는 최악의 경우 O(n^2)가 나올 수 있음.)

*/