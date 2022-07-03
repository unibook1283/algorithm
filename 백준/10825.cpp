#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Student {
	int k, e, m;
	string name;
};
bool cmp(const Student& u, const Student& v) {
	if (u.k > v.k) {
		return true;
	}
	else if (u.k == v.k) {
		if (u.e < v.e) {
			return true;
		}
		else if (u.e == v.e) {
			if (u.m > v.m) {
				return true;
			}
			else if (u.m == v.m) {
				if (u.name < v.name) return true;
			}
		}
	}
	return false;
}
int main() {
	int n;
	cin >> n;
	vector<Student> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].name >> v[i].k >> v[i].e >> v[i].m;
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << v[i].name << '\n';
	}


	return 0;
}