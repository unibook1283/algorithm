#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<int> d(n);
	for (int i = 0; i < n; i++)
		cin >> d[i];
	
	sort(d.begin(), d.end(), greater<>());
	int total_cal = c;
	int price = a;
	int ans = c / a;
	for (int i = 0; i < n; i++) {
		total_cal += d[i];
		price += b;
		int cal_per_one = total_cal / price;
		if (ans < cal_per_one)
			ans = cal_per_one;
	}
	cout << ans << '\n';

	return 0;
}