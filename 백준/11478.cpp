#include <iostream>
#include <set>
using namespace std;
int main() {
	string str;
	cin >> str;
	int length = str.size();

	set<string> s;
	for (int i = 0; i < length; i++) {
		for (int j = 1; j <= length - i; j++) {
			s.insert(str.substr(i, j));
		}
	}
	cout << s.size() << '\n';

	return 0;
}