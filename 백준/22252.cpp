#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;
int main() {
	int q;
	long long answer = 0;
	cin >> q;
	map<string, priority_queue<int>> m;
	for (int i = 0; i < q; i++) {
		int cmd , cnt;
		string name;
		cin >> cmd >> name;
		if (cmd == 1) {
			int k;
			cin >> k;
			for (int j = 0; j < k; j++) {
				int x;
				cin >> x;
				m[name].push(x);
			}
		}
		else {
			int b;
			cin >> b;
			if (m.find(name) == m.end()) continue;
			for (int j = 0; j < b; j++) {
				if (m[name].empty()) break;
				answer += m[name].top();
				m[name].pop();
			}
		}
	}
	cout << answer << '\n';

	return 0;
}