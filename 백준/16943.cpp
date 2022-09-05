#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool cmp(int u, int v) {
	return u > v;
}
int main() {
	string a;
	int b;
	cin >> a >> b;
	sort(a.begin(), a.end(), cmp);

	int ans = -1;
	do {
		if (a.front() == '0') continue;
		int temp = stoi(a);
		if (temp < b) {
			ans = temp;
			break;
		}
	} while (prev_permutation(a.begin(), a.end()));

	cout << ans << '\n';

	return 0;
}