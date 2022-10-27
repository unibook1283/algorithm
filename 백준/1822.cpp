#include <iostream>
#include <set>
using namespace std;
int main() {
	set<int> s;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.insert(x);
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		s.erase(x);
	}
	
	cout << s.size() << '\n';
	for (auto iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << ' ';
	}

	return 0;
}