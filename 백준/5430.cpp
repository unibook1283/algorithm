#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

deque<int> parse_string(string s, int n) {
	deque<int> ret;
	if (n == 0) return ret;
	int index = 1;
	for (int i = 0; i < n - 1; i++) {
		int end = s.find(',', index);
		string num = s.substr(index, end - index);
		ret.push_back(stoi(num));
		index = end + 1;
	}
	ret.push_back(stoi(s.substr(index, s.size() - 1 - index)));
	return ret;
}
void print_array(deque<int> d, bool rev) {
	cout << '[';
	if (!rev) {
		while (!d.empty()) {
			if (d.size() == 1) cout << d.front();
			else cout << d.front() << ',';
			d.pop_front();
		}
	}
	else {
		while (!d.empty()) {
			if (d.size() == 1) cout << d.back();
			else cout << d.back() << ',';
			d.pop_back();
		}
	}
	cout << "]\n";
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		string p;
		cin >> p;
		int n;
		cin >> n;
		string s;
		cin >> s;
		deque<int> d = parse_string(s, n);

		bool error = false;
		bool rev = false;
		for (char op : p) {
			if (op == 'R') {
				rev = !rev;
			}
			else {
				if (d.empty()) {
					error = true;
					break;
				}
				if (!rev)
					d.pop_front();
				else
					d.pop_back();
			}
		}
		if (error) cout << "error\n";
		else print_array(d, rev);
	}

	return 0;
}