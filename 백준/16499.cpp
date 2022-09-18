#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main() {
	int n;
	cin >> n;
	set<string> se;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		se.insert(s);
	}
	cout << se.size() << '\n';

	return 0;
}