#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int cache[101][101];
string W, S;
bool matchMemoized(int w, int s) {
	int& ret = cache[w][s];
	if (ret != -1) return ret;
	while (s < S.size() && w < W.size() &&
		(W[w] == '?' || W[w] == S[s])) {
		w++;
		s++;
	}
	if (w == W.size()) return ret = (s == S.size());
	if (W[w] == '*') {
		for (int skip = 0; s + skip <= S.size(); skip++)
			if (matchMemoized(w + 1, s + skip))
				return ret = 1;
	}
	return ret = 0;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> W;
		int n;
		cin >> n;
		vector<string> v;
		for (int i = 0; i < n; i++) {
			memset(cache, -1, sizeof(cache));
			cin >> S;
			if (matchMemoized(0, 0)) {
				v.push_back(S);
			}
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << '\n';
		}
	}

	return 0;
}