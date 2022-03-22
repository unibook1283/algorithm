#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	while (1) {
		string s;
		getline(cin, s);
		if (s == ".") break;

		stack<char> p;
		for (char c : s) {
			if (c == '(') p.push('(');
			else if (c == '[') p.push('[');
			else if (c == ')') {
				if (p.empty()) {
					p.push('t');
					break;
				}
				char top = p.top();
				p.pop();
				if (top != '(') {
					p.push('t');
					break;
				}
			}
			else if (c == ']') {
				if (p.empty()) {
					p.push('t');
					break;
				}
				char top = p.top();
				p.pop();
				if (top != '[') {
					p.push('t');
					break;
				}
			}
		}
		if (!p.empty()) cout << "no" << '\n';
		else cout << "yes" << '\n';
		while (!p.empty()) p.pop();
	}

	return 0;
}