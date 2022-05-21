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
�ߺ��� Ȯ���ϱ� ���ؼ� set�� �� �� �ֱ���. �迭 ���.
long long d[1000000001] �ϸ� '�迭�� �ʹ� Ů�ϴ�.' ���ͼ� set���� �ѵ�.
x != 0 �̰� �����ؾ߰ڴ�.
*/