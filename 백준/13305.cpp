#include <iostream>
#include <queue>
using namespace std;
struct cmp {
	bool operator() (pair<long long, long long> u, pair<long long, long long> v) {
		return u.first > v.first;
	}
};
int main() {
	int n;
	cin >> n;
	vector<long long> d(n - 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> d[i];
	}
	priority_queue <pair<long long, long long>, vector<pair<long long, long long>>, cmp> pq;	// (cost, index)
	for (long long i = 0; i < n; i++) {
		long long c;
		cin >> c;
		pq.push(make_pair(c, i));
	}

	long long index_check = n - 1;
	long long ans = 0;
	while (!pq.empty()) {
		long long c = pq.top().first;
		long long index = pq.top().second;
		pq.pop();
		if (index < index_check) {
			for (int i = index; i < index_check; i++) {
				ans += d[i] * c;
			}
			index_check = index;
		}
	}
	cout << ans << '\n';


	return 0;
}