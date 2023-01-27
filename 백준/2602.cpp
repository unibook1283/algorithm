#include <iostream>
#include <cstring>
using namespace std;
string str, devil, angel;
int cache[21][101][3];
int go(int s, int i, int turn) { //turn 0 : Ã³À½, 1 : devil, 2 : angel
	if (s == str.length()) return 1;
	if (i == devil.length()) return 0;
	int& ret = cache[s][i][turn];
	if (ret != -1) return ret;
	ret = 0;
	if (str[s] == devil[i])
		if (turn == 0 || turn == 2)
			ret += go(s + 1, i + 1, 1);
	if (str[s] == angel[i])
		if (turn == 0 || turn == 1)
			ret += go(s + 1, i + 1, 2);
	ret += go(s, i + 1, turn);
	return ret;
}
int main() {
	cin >> str >> devil >> angel;
	memset(cache, -1, sizeof(cache));
	cout << go(0, 0, 0) << '\n';

	return 0;
}