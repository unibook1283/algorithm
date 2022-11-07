#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m[10001];
int e[10001];
int n;
int heat() {
	vector<pair<int, int>> order;
	for (int i = 0; i < n; i++)
		order.push_back(make_pair(-e[i], i));
	sort(order.begin(), order.end());
	int ret = 0, beginEat = 0;
	for (int i = 0; i < n; i++) {
		int box = order[i].second;
		beginEat += m[box];
		ret = max(ret, beginEat + e[box]);
	}
	return ret;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> m[i];
		for (int i = 0; i < n; i++)
			cin >> e[i];
		cout << heat() << '\n';
	}

	return 0;
}