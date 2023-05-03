#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int sum = 0;
		int max_votes = -1, max_votes_index = -1;
		for (int i = 1; i <= n; i++) {
			int votes;
			cin >> votes;
			sum += votes;
			if (votes > max_votes) {
				max_votes = votes;
				max_votes_index = i;
			}
			else if (votes == max_votes) {
				max_votes_index = -1;
			}
		}

		if (max_votes_index == -1) {
			cout << "no winner\n";
		}
		else if (max_votes > sum / 2) {
			cout << "majority winner " << max_votes_index << '\n';
		}
		else {
			cout << "minority winner " << max_votes_index << '\n';
		}
	}

	return 0;
}