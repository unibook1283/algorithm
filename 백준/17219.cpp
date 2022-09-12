#include <iostream>
#include <map>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	map<string, string> m;
	for (int i = 0; i < n; i++) {
		string address, password;
		cin >> address >> password;
		m[address] = password;
	}
	for (int i = 0; i < k; i++) {
		string address;
		cin >> address;
		cout << m[address] << '\n';
	}

	return 0;
}