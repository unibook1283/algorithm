#include <iostream>
#include <vector>
using namespace std;
int n;
bool check[11];
vector<pair<int ,int>> sale[11];	// (물약 번호, 할인 개수)
int ans = 987654321;
void go(int index, int coin, vector<int> price) {
	if (index == n) {
		ans = min(ans, coin);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			check[i] = true;
			vector<int> temp = price;
			for (int j = 0; j < sale[i].size(); j++) {
				int s_index = sale[i][j].first;
				int s_price = sale[i][j].second;
				temp[s_index] -= s_price;
				if (temp[s_index] <= 0) temp[s_index] = 1;
			}
			go(index + 1, coin + price[i], temp);
			check[i] = false;
		}
	}
}
int main() {
	cin >> n;
	vector<int> price(n);
	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		for (int j = 0; j < p; j++) {
			int aj, dj;
			cin >> aj >> dj;
			aj--;
			sale[i].push_back(make_pair(aj, dj));
		}
	}
	go(0, 0, price);
	cout << ans << '\n';

	return 0;
}