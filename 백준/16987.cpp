#include <iostream>
#include <vector>
using namespace std;
int n;
vector<pair<int, int>> a;	// (내구도, 무게)
int ans = 0;
int get_broken_count() {
	int cnt = 0;
	for (int i = 0; i < a.size(); i++) {
		//cout << a[i].first << ' ' << a[i].second << '\n';
		if (a[i].first <= 0) cnt++;
	}
	return cnt;
}
void go(int index) {
	if (index == n) {
		int broken_count = get_broken_count();
		ans = max(ans, broken_count);
		return;
	}
	if (a[index].first <= 0) {
		go(index + 1);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (i == index) continue;
		if (a[i].first <= 0) {
			go(index + 1);
			continue;
		}
		a[index].first -= a[i].second;
		a[i].first -= a[index].second;
		go(index + 1);
		a[index].first += a[i].second;
		a[i].first += a[index].second;
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, w;
		cin >> s >> w;
		a.push_back(make_pair(s, w));
	}
	go(0);
	cout << ans << '\n';

	return 0;
}