#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct nation {
	int a;
	int g;
	int s;
	int b;
};
bool compare(nation a1, nation a2) {
	if (a1.g == a2.g) {
		if (a1.s == a2.s) {
			return a1.b > a2.b;
		}
		else {
			return a1.s > a2.s;
		}
	}
	else {
		return a1.g > a2.g;
	}
}
bool equal(nation a1, nation a2) {
	if (a1.g == a2.g && a1.s == a2.s && a1.b == a2.b) return true;
	return false;
}
int main() {
	int n, k;
	cin >> n >> k;

	vector<nation> v;
	for (int i = 0; i < n; i++) {
		int a, g, s, b;
		cin >> a >> g >> s >> b;
		v.push_back({ a,g,s,b });
	}
	sort(v.begin(), v.end(), compare);

	nation prev;
	int redun = 0;
	for (int i = 0; i < n; i++) {
		if (i != 0 && equal(prev, v[i])) {
			redun++;
		}
		else {
			prev = v[i];
			redun = 0;
		}
		if (v[i].a == k) {
			cout << i - redun + 1 << '\n';
			break;
		}
	}


	return 0;
}