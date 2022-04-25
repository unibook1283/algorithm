#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	vector<string> v;
	while (!s.empty()) {
		v.push_back(s);
		s.erase(0, 1);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}

	return 0;
}