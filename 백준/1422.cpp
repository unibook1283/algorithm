#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int first_num_cnt[10];
bool cmp(string a, string b) {
	if (a.length() == b.length()) {
		return a > b;
	}
	return a.length() > b.length();
}
bool cmp2(string a, string b) {
	return a + b > b + a;
}
int main() {
	int k, n;
	cin >> k >> n;
	vector<string> a(k);
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end(), cmp);
	
	vector<string> v;
	for (int i = 0; i < k; i++)
		v.push_back(a[i]);
	for (int i =k; i < n; i++)
		v.push_back(a[0]);

	sort(v.begin(), v.end(), cmp2);
	for (int i = 0; i < n; i++) {
		cout << v[i];
	}
	cout << '\n';
	
	return 0;
}