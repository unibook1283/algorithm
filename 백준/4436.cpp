#include <iostream>
#include <cstring>
using namespace std;
bool check[10];
void update_check(long long an) {
	while (an > 0) {
		int r = an % 10;
		check[r] = true;
		an /= 10;
	}
}
bool finish_check() {
	for (int i = 0; i < 10; i++) {
		if (check[i] == false) return false;
	}
	return true;
}
int main() {
	long long n;
	while (cin >> n) {
		memset(check, false, sizeof(check));
		long long an = 0;
		int i = 0;
		while (1) {
			i++;
			an += n;
			update_check(an);
			if (finish_check()) {
				cout << i << '\n';
				break;
			}
		}
	}

	return 0;
}