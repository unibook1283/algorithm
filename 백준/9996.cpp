#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	cin >> n;
	string pat, front, back;
	cin >> pat;

	for (int i = 0; i < pat.size(); i++) {
		if (pat[i] == '*') {
			front = pat.substr(0, i);
			back = pat.substr(i + 1, pat.size() - i - 1);
			break;
		}
	}
	while (n--) {
		string s, f, b;
		cin >> s;
		if (pat.size() - 1 > s.size()) {
			cout << "NE\n";
			continue;
		}
		f = s.substr(0, front.size());
		b = s.substr(s.size() - back.size(), back.size());

		if (front == f && back == b) cout << "DA\n";
		else cout << "NE\n";
	}

	return 0;
}