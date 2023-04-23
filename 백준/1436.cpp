#include <iostream>
#include <string>
using namespace std;
bool is_end_number(int n) {
	while (n) {
		string s = to_string(n % 1000);
		if (s == "666") return true;
		n /= 10;
	}
	return false;
}
int main() {
	int n;
	cin >> n;
	
	int answer = 0;
	while (n) {
		answer++;
		if (is_end_number(answer)) {
			n--;
		}
	}

	cout << answer << '\n';

	return 0;
}