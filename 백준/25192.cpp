#include <iostream>
#include <set>
using namespace std;
int main() {
	set<string> s;
	int n;
	cin >> n;
	int answer = 0;
	while (n--) {
		string str;
		cin >> str;
		if (str == "ENTER") {
			s.clear();
			continue;
		}
		if (s.find(str) == s.end()) {
			answer++;
			s.insert(str);
		}
	}
	cout << answer << '\n';

	return 0;
}