#include <iostream>
#include <set>
using namespace std;
bool is_d(string str, int d) {
	set<string> s;
	for (int i = 0; i < str.length() - d; i++) {
		string cur = "";
		cur += str.substr(i, 1) + str.substr(i + d, 1);
		if (s.find(cur) != s.end()) return false;
		s.insert(cur);
	}
	return true;
}
int main() {
	while (1) {
		string str;
		cin >> str;
		if (str == "*") break;

		// 길이 1, 2 예외처리
		if (str.length() == 1 || str.length() == 2) {
			cout << str << " is surprising.\n";
			continue;
		}

		bool surprise = true;
		for (int i = 1; i < str.length(); i++) {
			if (!is_d(str, i)) {
				surprise = false;
				break;
			}
		}

		if (surprise) cout << str << " is surprising.\n";
		else cout << str << " is NOT surprising.\n";
	}


	return 0;
}