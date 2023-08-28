#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int last_odd_index = -1;
	int last_even_index = -1;
	bool evenness;
	for (int i = 1; i <= n; i++) {
		int number;
		cin >> number;
		if (number % 2 == 0) {
			if (last_even_index != -1) {
				evenness = true;
			}
			last_even_index = i;
		}
		else {
			if (last_odd_index != -1) {
				evenness = false;
			}
			last_odd_index = i;
		}
	}
	if (evenness) cout << last_odd_index << '\n';
	else cout << last_even_index << '\n';

	return 0;
}