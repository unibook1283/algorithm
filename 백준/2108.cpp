#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int find_mode(vector<int> count) {
	int max_value = -1;
	int smallest_max_index = -1;
	int second_small_max_index = -1;
	for (int i = 8000; i >= 0; i--) {
		if (count[i] > max_value) {
			max_value = count[i];
			smallest_max_index = i;
			second_small_max_index = -1;
		}
		else if (count[i] == max_value) {
			second_small_max_index = smallest_max_index;
			smallest_max_index = i;
		}
	}
	return second_small_max_index == -1 ? smallest_max_index - 4000 : second_small_max_index - 4000;
}
int main() {
	int n;
	cin >> n;
	vector<int> numbers(n), count(8001);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
		sum += numbers[i];
		count[numbers[i] + 4000]++;
	}
	sort(numbers.begin(), numbers.end());
	int mean, mid, mode, range;
	mean = round((float)sum / n);
	mid = numbers[n / 2];
	mode = find_mode(count);
	range = numbers[n - 1] - numbers[0];
	cout << mean << '\n';
	cout << mid << '\n';
	cout << mode << '\n';
	cout << range << '\n';

	return 0;
}