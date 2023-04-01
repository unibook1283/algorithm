#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void insertAnswer(vector<long long>& v, long long a, long long b, long long c) {
	v.clear();
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
}
int main() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	vector<long long> answer;
	long long minValue = 3000000001;
	for (int i = 0; i < n - 2; i++) {
		int left = i + 1, right = n - 1;
		while (left < right) {
			long long value = v[i] + v[left] + v[right];
			if (abs(value) < minValue) {
				minValue = abs(value);
				insertAnswer(answer, v[i], v[left], v[right]);
			}
			if (value == 0) {
				for (long long x : answer)
					cout << x << ' ';
				cout << '\n';
				return 0;
			}
			else if (value < 0) {
				left++;
			}
			else {
				right--;
			}
		}
	}
	for (long long x : answer)
		cout << x << ' ';
	cout << '\n';

	return 0;
}