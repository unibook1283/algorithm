#include <iostream>
using namespace std;
int a[51];
void swap_them(int target_index, int swaper_index) {
	int temp = a[swaper_index];
	for (int i = swaper_index; i > target_index; i--) {
		a[i] = a[i - 1];
	}
	a[target_index] = temp;
}
int main() {
	int n, s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> s;

	int target_index = 0;
	while (s > 0 && target_index < n) {
		int target = a[target_index];
		int swaper_index = -1;
		int swaper = 0;
		for (int i = 1; i <= s && target_index + i < n; i++) {
			if (target < a[target_index + i] && swaper < a[target_index + i]) {
				swaper = a[target_index + i];
				swaper_index = target_index + i;
			}
		}
		if (swaper_index == -1) {
			target_index++;
			continue;
		}
		swap_them(target_index, swaper_index);
		s -= swaper_index - target_index;
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << '\n';

	return 0;
}