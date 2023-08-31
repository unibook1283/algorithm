#include <iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	string quack = "quack";
	int count[5] = { 0, };
	int answer = 0;
	int cur_duck = 0;
	for (char ch : s) {
		for (int i = 0; i < 5; i++) {
			if (ch == quack[i]) {
				if (i == 0) {
					count[0]++;
					cur_duck++;
					answer = max(answer, cur_duck);
					break;
				}
				if (count[i - 1] > 0) {
					count[i - 1]--;
					count[i]++;
					if (i == 4) cur_duck--;
				}
				else {
					cout << -1 << '\n';
					return 0;
				}
			}
		}
	}
	for (int i = 0; i < 4; i++)
		if (count[i] != 0) {
			answer = -1;
			break;
		}
	cout << answer << '\n';

	return 0;
}