#include <iostream>
#include <algorithm>
using namespace std;
int a[1001];
bool compare(int i, int j) {
	return j < i;
}
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n, compare);
	
	cout << a[k - 1] << '\n';


	return 0;
}