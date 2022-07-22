#include <iostream>
#include <stack>
using namespace std;
int main() {
	int n;
	string ans;
	cin >> n;

	stack<int> s;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		while (cnt <= x) {
			s.push(cnt++);
			ans += "+";
		}
		if (s.top() == x) {
			s.pop();
			ans += "-";
		}
		else {
			cout << "NO\n";
			return 0;
		}
	}
	for (char ch : ans) {
		cout << ch << '\n';
	}


	return 0;
}