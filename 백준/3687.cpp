#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string cache[101][2][2];	// (n,  isFirst, small/big)
int match[10] = { 6,2,5,5,4,5,6,3,7,6 };
string smaller(string a, string b) {
	if (a.length() == b.length())
		return min(a, b);
	return a.length() < b.length() ? a : b;
}
string bigger(string a, string b) {
	if (a.length() == b.length())
		return max(a, b);
	return a.length() > b.length() ? a : b;
}
string smallest(int n, int isFirst) {
	if (n == 0) return "";
	string& ret = cache[n][isFirst][0];
	if (ret != "-1") return ret;
	ret = "99999999999999999";
	for (int i = 0; i < 10; i++) {
		if (isFirst == 1 && i == 0) continue;
		if (n - match[i] >= 0) {
			char ch = '0' + i;
			string num = ch + smallest(n - match[i], 0);
			ret = smaller(ret, num);
		}
	}
	return ret;
}
string biggest(int n, int isFirst) {
	if (n == 0) return "";
	string& ret = cache[n][isFirst][1];
	if (ret != "-1") return ret;
	ret = "";
	for (int i = 0; i < 10; i++) {
		if (isFirst == 1 && i == 0) continue;
		if (n - match[i] >= 0) {
			char ch = '0' + i;
			string num = ch + biggest(n - match[i], 0);
			ret = bigger(ret, num);
		}
	}
	return ret;
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				cache[i][j][k] = "-1";
	while (t--) {
		int n;
		cin >> n;
		cout << smallest(n, 1) << ' ';
		cout << biggest(n, 1) << '\n';
	}

	return 0;
}