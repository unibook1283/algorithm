#include <iostream>
#include <cstring>
using namespace std;
int n;
string s;
string pattern = "DKSH";
long long cache[100001][4];
long long go(int s_index, int p_index) {	// (전체 string의 index, DKSH의 index)
	if (p_index == 4) {
		return 1;
	}
	if (s_index == n) {
		return 0;
	}
	long long& ret = cache[s_index][p_index];
	if (ret != -1) return ret;
	ret = 0;
	if (s[s_index] == pattern[p_index]) {
		ret += go(s_index + 1, p_index + 1);
	}
	ret += go(s_index + 1, p_index);
	return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s;
	memset(cache, -1, sizeof(cache));
	cout << go(0, 0) << '\n';;
	
	return 0;
}