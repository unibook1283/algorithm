#include <iostream>
#include <set>
#include <stack>
using namespace std;
string a[500001];
int main() {
	set<string> s;
	stack<string> st;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}

	for (int i = m - 1; i >= 0; i--) {
		if (s.find(a[i]) == s.end()) {
			s.insert(a[i]);
			st.push(a[i]);
		}
	}


	while (!st.empty() && n--) {
		cout << st.top() << '\n';
		st.pop();
	}

	return 0;
}