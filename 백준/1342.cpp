#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	int len = s.size();
	int ans = 0;
	do {
		bool lucky = true;
		for (int i = 0; i < len - 1; i++) {
			if (s[i] == s[i + 1]) lucky = false;
		}
		if (lucky) ans++;
	} while (next_permutation(s.begin(), s.end()));
	cout << ans << '\n';

	return 0;
}