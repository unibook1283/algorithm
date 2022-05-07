#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m;
	cin >> m;
	string op;
	int x, set = 0;
	while (m--) {
		cin >> op;
		if (op == "add") {
			cin >> x; x--;
			set |= (1 << x);
		}
		else if (op == "remove") {
			cin >> x; x--;
			set &= ~(1 << x);
		}
		else if (op == "check") {
			cin >> x; x--;
			if (set & (1 << x)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (op == "toggle") {
			cin >> x; x--;
			set ^= (1 << x);
		}
		else if (op == "all") {
			set = (1 << 20) - 1;
		}
		else if (op == "empty") {
			set = 0;
		}
	}

	return 0;
}