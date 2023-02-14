#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	map<string, int> a, b;
	vector<string> c(k);
	string menu;
	int price;
	for (int i = 0; i < n + m; i++) {
		cin >> menu >> price;
		if (i < n) {
			a[menu] = price;
		}
		else {
			b[menu] = price;
		}
	}
	for (int i = 0; i < k; i++)
		cin >> c[i];
	
	int o;
	cin >> o;
	long long a_sum = 0, b_sum = 0;
	bool order_c = false;
	for (int i = 0; i < o; i++) {
		string menu;
		cin >> menu;
		if (a[menu] > 0) {
			a_sum += a[menu];
		}
		else if (b[menu] > 0) {
			b_sum += b[menu];
		}
		else {
			if (order_c) {
				cout << "No\n";
				return 0;
			}
			else order_c = true;
		}
	}
	if (b_sum > 0 && a_sum < 20000) cout << "No\n";
	else if (order_c && a_sum + b_sum < 50000) cout << "No\n";
	else cout << "Okay\n";

	return 0;
}