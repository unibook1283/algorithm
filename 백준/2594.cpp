#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int convert_to_minute(int time) {
	int hour = time / 100;
	int min = time % 100;
	return hour * 60 + min;
}
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int from, to;
		cin >> from >> to;
		from = convert_to_minute(from);
		to = convert_to_minute(to);
		v.push_back(make_pair(from, to));
	}
	
	sort(v.begin(), v.end());
	int prev_end = 600;
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		int dif = v[i].first - prev_end;
		if (i == 0) dif -= 10;
		else dif -= 20;

		prev_end = max(prev_end, v[i].second);
		if (dif < 0) {
			continue;
		}
		maxi = max(maxi, dif);
	}
	maxi = max(maxi, 1310 - prev_end);

	cout << maxi << '\n';

	return 0;
}