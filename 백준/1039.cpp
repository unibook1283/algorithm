#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int n, k;
bool check[1000001][11];
int ans = -1;
string swap(string x, int i, int j) {
	char temp = x[i];
	x[i] = x[j];
	x[j] = temp;
	return x;
}
void dfs(string x, int cal) {
	if (x[0] == '0') return;
	if (cal == k) {
		ans = max(ans, stoi(x));
		return;
	}
	int len = x.length();
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			string s = swap(x, i, j);
			if (check[stoi(s)][cal + 1]) continue;
			check[stoi(s)][cal + 1] = true;
			dfs(s, cal + 1);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	dfs(to_string(n), 0);
	cout << ans << '\n';
}