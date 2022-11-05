#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> you(n), me(n);
		for (int i = 0; i < n; i++)
			cin >> you[i];
		for (int i = 0; i < n; i++)
			cin >> me[i];
		sort(you.begin(), you.end());
		sort(me.begin(), me.end());

		int you_index = 0, me_index = 0, cnt = 0;
		while (you_index < n && me_index < n) {
			if (you[you_index] <= me[me_index]) {
				cnt++;
				you_index++;
			}
			me_index++;
		}
		cout << cnt << '\n';
	}

	return 0;
}