#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
bool check[500001];
using namespace std;
struct cmp {
	bool operator()(pair<int, long long>& u, pair<int, long long>& v) {
		return u.second > v.second;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<pair<long long, long long>> civil;
	vector<pair<long long, long long>> store;
	for (int i = 0; i < n; i++) {
		long long l, r;
		cin >> l >> r;
		civil.push_back(make_pair(l, r));
	}
	for (int i = 0; i < m; i++) {
		long long p, x;
		cin >> p >> x;
		store.push_back(make_pair(p, x));
	}
	sort(civil.begin(), civil.end());
	sort(store.begin(), store.end());

	int ans = 0;
	int civil_index = 0;
	// (civilÀÇ index, right °ª)
	priority_queue<pair<int, long long>, vector<pair<int, long long>>, cmp> pq;
	for (int i = 0; i < m; i++) {
		long long pay = store[i].first;
		while (civil_index < n && civil[civil_index].first <= pay) {
			if (!check[civil_index] && civil[civil_index].second >= pay) {
				pq.push(make_pair(civil_index, civil[civil_index].second));
			}
			civil_index++;
		}
		while (!pq.empty() && store[i].second != 0) {
			int index = pq.top().first;
			pq.pop();
			store[i].second--;
			check[index] = true;
			ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}
/*
19580
*/