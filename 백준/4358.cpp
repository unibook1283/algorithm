#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
	map<string, float> m;
	string s;
	int sum = 0;
	while (getline(cin, s)) {
		m[s]++;
		sum++;
	}
	cout << fixed;
	cout.precision(4);
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << ' ' << (iter->second / sum) * 100 << '\n';
	}

	return 0;
}