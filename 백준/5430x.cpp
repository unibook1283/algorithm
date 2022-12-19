#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;
deque<int> parsing(string s) {
	deque<int> ret;
	if (s.length() == 2) return ret;
	int start = 1;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ',' || s[i] == ']') {
			ret.push_back(stoi(s.substr(start, i)));
			start = i + 1;
		}
	}
	return ret;
}
void print_string(deque<int> nums) {
	if (nums.empty()) {
		cout << "[]\n";
		return;
	}
	cout << '[';
	for (auto p = nums.begin(); p != nums.end(); p++) {
		if (p != nums.end() - 1) cout << *p << ',';
		else cout << *p;
	}
	cout << "]\n";
}
void print_string_reverse(deque<int> nums) {
	if (nums.empty()) {
		cout << "[]\n";
		return;
	}
	cout << '[';
	for (auto p = nums.rbegin(); p != nums.rend(); p++) {
		if (p != nums.rend() - 1) cout << *p << ',';
		else cout << *p;
	}
	cout << "]\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		string p;
		cin >> p;
		int n;
		cin >> n;
		string num_string;
		cin >> num_string;
		deque<int> nums = parsing(num_string);
		bool reversed = false;
		bool error = false;
		for (char ch : p) {
			if (ch == 'R') {
				reversed = !reversed;
			}
			else if (ch == 'D') {
				if (nums.empty()) {
					error = true;
					break;
				}
				if (!reversed) nums.pop_front();
				else nums.pop_back();
			}
		}
		if (error) {
			cout << "error\n";
			continue;
		}
		if (!reversed) print_string(nums);
		else print_string_reverse(nums);
	}

	return 0;
}