#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	getline(cin, s);
	string ucpc = "UCPC";
	int i = 0;
	for (char ch : s) {
		if (ch == ucpc[i]) {
			i++;
		}
		if (i == 4) {
			cout << "I love UCPC\n";
			return 0;
		}
	}
	cout << "I hate UCPC\n";

	return 0;
}