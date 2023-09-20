#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int a[10];
int n, m;
vector<int> v;
set<vector<int>> s;
void go(int index) {
	if (v.size() > m) return;
	if (index == n) {
		if (v.size() == m) {
			s.insert(v);
		}
		return;
	}
	go(index + 1);
	v.push_back(a[index]);
	go(index + 1);
	v.pop_back();
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	go(0);
	
	for (vector<int> vec : s) {
		for (int x : vec) {
			cout << x << ' ';
		}
		cout << '\n';
	}

	return 0;
}