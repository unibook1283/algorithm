#include <iostream>
using namespace std;
int a[2000];
int d[2000];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] > a[i] && d[j] + 1 > d[i]) {
				d[i] = d[j] + 1;
			}
		}
	}
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		maxi = max(maxi, d[i]);
	}
	cout << n - maxi << '\n';
	
	return 0;
}
/*
d[i] = 1;
�ʱⰪ�� �� �����༭ �����ɸ�.
������ �� �ݷ�:
8
1 2 3 4 5 6 8 7
-> d[i] : 1 0 0 0 0 0 0 1
��� : 7
���� : 6
*/