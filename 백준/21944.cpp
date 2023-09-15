#include <iostream>
#include <set>
#include <map>
using namespace std;
int main() {
	int n;
	cin >> n;
	set<pair<int, int>> S, s[101];
	map<int, int> level, group;
	while (n--) {
		int p, l, g;
		cin >> p >> l >> g;
		S.insert({ l,p });
		s[g].insert({ l,p });
		level[p] = l;
		group[p] = g;
	}
	int m;
	cin >> m;
	while (m--) {
		string op;
		cin >> op;
		if (op == "recommend") {
			int g, x;
			cin >> g >> x;
			if (x == 1) {
				cout << s[g].rbegin()->second << '\n';
			}
			else {
				cout << s[g].begin()->second << '\n';
			}
		}
		else if (op == "recommend2") {
			int x;
			cin >> x;
			if (x == 1) {
				cout << S.rbegin()->second << '\n';
			}
			else {
				cout << S.begin()->second << '\n';
			}
		}
		else if (op == "recommend3") {
			int x, L;
			cin >> x >> L;
			auto iter = S.lower_bound({ L,0 });
			if (iter == S.end()) {
				cout << -1 << '\n';
				continue;
			}
			if (x == 1) {
				cout << iter->second << '\n';
			}
			else {
				if (iter == S.begin()) {
					cout << -1 << '\n';
				}
				else {
					iter--;
					cout << iter->second << '\n';
				}
			}
		}
		else if (op == "add") {
			int p, l, g;
			cin >> p >> l >> g;
			S.insert({ l,p });
			s[g].insert({ l,p });
			level[p] = l;
			group[p] = g;
		}
		else {
			int p;
			cin >> p;
			S.erase({ level[p],p });
			s[group[p]].erase({ level[p],p });
			level.erase(p);
			group.erase(p);
		}
	}

	return 0;
}