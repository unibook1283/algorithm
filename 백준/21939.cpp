#include <iostream>
#include <set>
#include <map>
using namespace std;
int main() {
	int n;
	cin >> n;
	set<pair<int, int>> s;
	map<int, int> diff;
	while (n--) {
		int p, l;
		cin >> p >> l;
		s.insert({ l,p });
		diff[p] = l;
	}
	int m;
	cin >> m;
	while (m--) {
		string op;
		cin >> op;
		if (op == "recommend") {
			int x;
			cin >> x;
			if (x == 1) {
				cout << s.rbegin()->second << '\n';
			}
			else {
				cout << s.begin()->second << '\n';
			}
		}
		else if (op == "add") {
			int p, l;
			cin >> p >> l;
			s.insert({ l,p });
			diff[p] = l;
		}
		else {
			int p;
			cin >> p;
			s.erase({ diff[p],p });
			diff.erase(p);
		}
	}

	return 0;
}