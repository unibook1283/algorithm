#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
vector<pair<int, int>> v;
int cache[101][100001];
bool is_possible(int index, int sum) {
	if (sum == 0)
		return true;
	if (index == n)
		return false;
	int& ret = cache[index][sum];
	if (ret != -1) return ret;
	ret = false;
	int amount = v[index].first;
	int count = v[index].second;
	for (int i = 0; i <= count; i++) {
		if (sum - amount * i >= 0)
			if (ret = ret | is_possible(index + 1, sum - amount * i))
				return true;
	}
	return false;
}
int main() {
	for (int i = 0; i < 3; i++) {
		cin >> n;
		int sum = 0;
		v.clear();
		for (int i = 0; i < n; i++) {
			int amount, count;
			cin >> amount >> count;
			v.push_back(make_pair(amount, count));
			sum += amount * count;
		}

		if (sum % 2 == 1) {
			cout << "0\n";
			continue;
		}
		sum /= 2;

		sort(v.begin(), v.end(), greater<>());
		memset(cache, -1, sizeof(cache));
		if (is_possible(0, sum))
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}