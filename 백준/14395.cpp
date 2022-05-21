#include <iostream>
#include <queue>
#include <set>
using namespace std;
const long long limit = 1000000000LL;
int main() {
	long long s, t;
	cin >> s >> t;

	set<long long> check;
	queue<pair<long long, string>> q;
	q.push(make_pair(s, ""));
	check.insert(s);
	while (!q.empty()) {
		long long x = q.front().first;
		string str = q.front().second;
		q.pop();
		if (x == t) {
			if (str.length() == 0) {
				str = "0";
			}
			cout << str << '\n';
			return 0;
		}
		if (x * x <= limit && check.count(x * x) == 0) {
			q.push(make_pair(x * x, str + "*"));
			check.insert(x * x);
		}
		if (x + x <= limit && check.count(x + x) == 0) {
			q.push(make_pair(x + x, str + "+"));
			check.insert(x + x);
		}
		if (check.count(0) == 0) {
			q.push(make_pair(0, str + "-"));
			check.insert(0);
		}
		if (x != 0 && check.count(1) == 0) {
			q.push(make_pair(1, str + "/"));
			check.insert(1);
		}
	}
	cout << -1 << '\n';

	return 0;
}
/*
중복을 확인하기 위해서 set을 쓸 수 있구나. 배열 대신.
long long d[1000000001] 하면 '배열이 너무 큽니다.' 나와서 set으로 한듯.
x != 0 이거 조심해야겠다.
*/