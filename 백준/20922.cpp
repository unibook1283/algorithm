#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	map<int, int> m;	// (�ش� ���ڰ� left, right ���̿��� �� �� ���Դ���)
	int left = 0, right = 0;
	int max_len = 0;
	while (left <= right) {
		if (right == n) break;
		if (m[v[right]] == k) {
			m[v[left++]]--;
		}
		else {
			m[v[right++]]++;
			max_len = max(max_len, right - left);
		}
	}
	cout << max_len << '\n';

	return 0;
}