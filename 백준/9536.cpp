#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
bool contains(vector<string> v, string s) {
	for (string i : v) {
		if (i == s) return true;
	}
	return false;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		string buf;
		getline(cin, buf);
		string s;
		getline(cin, s);

		vector<string> v;
		while (1) {
			string a, b, c;
			cin >> a >> b >> c;
			if (a == "what") {
				string d, e;
				cin >> d >> e;
				break;
			}
			v.push_back(c);
		}

		stringstream ss;
		ss.str(s);
		string token, res = "";
		while (ss >> token) {
			if (!contains(v, token)) {
				res += token + " ";
			}
		}
		cout << res << '\n';
	}


	return 0;
}