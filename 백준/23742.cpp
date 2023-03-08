#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;

	long long positiveSum = 0;
	int positiveCnt = 0;
	vector<int> negative;
	for (int i = 0; i < n; i++) {
		int x; 
		cin >> x;
		if (x >= 0) {
			positiveSum += x;
			positiveCnt++;
		}
		else {
			negative.push_back(x);
		}
	}
	sort(negative.begin(), negative.end(), greater<>());

	long long ans = 0;
	for (int i = 0; i < negative.size(); i++) {
		int x = negative[i];
		if (positiveSum * positiveCnt + x <= (positiveSum + x) * (positiveCnt + 1)) {
			positiveSum += x;
			positiveCnt++;
		}
		else {
			ans += x;
		}
	}
	cout << ans + positiveSum * positiveCnt << '\n';

	return 0;
}