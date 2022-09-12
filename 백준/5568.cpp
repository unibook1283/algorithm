#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;
int n, k;
bool check[11];
set<string> s;
void go(vector<int>& v, vector<int>& picked) {
	if (picked.size() == k) {
		string res;
		for (int i = 0; i < k; i++) {
			res += to_string(picked[i]);
		}
		s.insert(res);
	}
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			check[i] = true;
			picked.push_back(v[i]);
			go(v, picked);
			picked.pop_back();
			check[i] = false;
		}
	}
}
int main() {
	cin >> n >> k;
	vector<int> v(n), picked;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	go(v, picked);
	cout << s.size() << '\n';

	return 0;
}