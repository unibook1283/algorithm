#include <iostream>
#include <string>
using namespace std;
int n;
bool finish = false;
string res;
void go(string s) {
	if (finish) return;
	int len = s.length();
	for (int i = 1; i <= len / 2; i++) {
		if (s.substr(len - 2 * i, i) == s.substr(len - i)) return;
	}
	if (len == n) {
		res = s;
		finish = true;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		go(s + to_string(i));
	}
}
int main() {
	cin >> n;
	go("");
	cout << res << '\n';

	return 0;
}