#include <iostream>
#include <vector>
using namespace std;
pair<int, string> books[17];
const int INF = 987654321;
bool is_satisfied(string t, vector<int> alpha) {
	for (char ch : t) {
		if (alpha[ch - 'A'] == 0) return false;
		alpha[ch - 'A']--;
	}
	return true;
}
int main() {
	string t;
	int n;
	cin >> t >> n;
	for (int i = 0; i < n; i++) {
		cin >> books[i].first >> books[i].second;
	}

	int answer = INF;
	for (int i = 0; i < (1 << n); i++) {
		int price_sum = 0;
		vector<int> alpha(26);
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				for (char ch : books[j].second) {
					alpha[ch - 'A']++;
				}
				price_sum += books[j].first;
			}
		}
		if (is_satisfied(t, alpha)) {
			answer = min(answer, price_sum);
		}
	}

	cout << (answer == INF ? -1 : answer) << '\n';

	return 0;
}