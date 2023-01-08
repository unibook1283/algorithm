#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int length_of_string_containing_k_ch(string w, int k, int index) {
	char ch = w[index];
	int start = index + 1;
	int cnt;
	for (cnt = 1; cnt < k; cnt++) {
		int next = w.find(ch, start);
		if (next == -1) break;
		start = next + 1;
	}
	if (cnt == k) {
		return start - index;
	}
	return -1;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		string w;
		int k;
		cin >> w >> k;
		vector<int> v;
		for (int i = 0; i < w.size(); i++) {
			int length = length_of_string_containing_k_ch(w, k, i);
			if (length != -1) {
				v.push_back(length);
			}
		}
		sort(v.begin(), v.end());
		if (v.empty())
			cout << "-1\n";
		else
			cout << v.front() << ' ' << v.back() << '\n';
	}

	return 0;
}