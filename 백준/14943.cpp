#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	long long ans = 0;
	priority_queue<pair<int, long long>> plus, minus;	// (-index, value)
	for (int i = 0; i < n; i++) {
		if (v[i] > 0) {
			bool finish = false;	// 해당 index의 벼룩을 전부 판매
			while (!minus.empty()) {
				int index = -minus.top().first;
				long long m = minus.top().second;
				minus.pop();
				if (v[i] < m) {
					m -= v[i];
					minus.push(make_pair(-index, m));
					ans += v[i] * (i - index);
					finish = true;
					break;
				}
				else {
					v[i] -= m;
					ans += m * (i - index);
				}
			}
			if (!finish) plus.push(make_pair(-i, v[i]));
		}
		else if (v[i] < 0) {
			int value = -v[i];
			bool finish = false;
			while (!plus.empty()) {
				int index = -plus.top().first;
				long long m = plus.top().second;
				plus.pop();
				if (value < m) {
					m -= value;
					plus.push(make_pair(-index, m));
					ans += value * (i - index);
					finish = true;
					break;
				}
				else {
					value -= m;
					ans += m * (i - index);
				}
			}
			if (!finish) minus.push(make_pair(-i, value));
		}
	}
	cout << ans << '\n';

	return 0;
}