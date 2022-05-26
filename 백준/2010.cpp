#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;

	int sum = 0;
	for  (int i = 0; i < n; i++) {
		int plugs;
		cin >> plugs;
		sum += plugs;
		if (i == 0) continue;
		sum--;
	}
	cout << sum << '\n';



	return 0;
}