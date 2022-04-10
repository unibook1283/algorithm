#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool isPalindrome(int num) {
	for (int i = 2; i <= 64; i++) {
		string s;
		int n = num;
		while (n > 0) {
			s.push_back(n % i);
			n /= i;
		}
		string rs;
		rs = s;
		reverse(rs.begin(), rs.end());
		if (rs == s) return true;
	}
	return false;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int num;
		cin >> num;
		cout << isPalindrome(num) << '\n';
	}

	return 0;
}