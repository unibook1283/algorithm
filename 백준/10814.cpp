#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Member {
	int age;
	string name;
};
bool cmp(const Member& u, const Member& v) {
	return u.age < v.age;
}
int main() {
	int n;
	cin >> n;
	vector<Member> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].age >> v[i].name;
	}
	stable_sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << v[i].age << ' ' << v[i].name << '\n';
	}

	return 0;
}