/*
#include <iostream>
#include <vector>
using namespace std;
const int INF = 9999, CLOCKS = 16, SWITCHES = 10;
vector<vector<int>> switches;
bool areAligned(vector<int>& clocks) {
	for (int i = 0; i < CLOCKS; i++) {
		if (clocks[i] != 12) return false;
	}
	return true;
}
void push(vector<int>& clocks, int swtch) {
	for (int i = 0; i < switches[swtch].size(); i++) {
		int clock = switches[swtch][i];
		clocks[clock] += 3;
		if (clocks[clock] == 15) clocks[clock] = 3;
	}
}
int go(vector<int>& clocks, int swtch) {
	if (swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;
	int ret = INF;
	for (int cnt = 0; cnt < 4; cnt++) {
		ret = min(ret, cnt + go(clocks, swtch + 1));
		push(clocks, swtch);
	}
	return ret;
}
int main() {
	switches.push_back(vector<int>{ 0,1,2 });
	switches.push_back(vector<int>{ 3,7,9,11 });
	switches.push_back(vector<int>{ 4,10,14,15 });
	switches.push_back(vector<int>{ 0,4,5,6,7 });
	switches.push_back(vector<int>{ 6,7,8,10,12 });
	switches.push_back(vector<int>{ 0,2,14,15 });
	switches.push_back(vector<int>{ 3,14,15 });
	switches.push_back(vector<int>{ 4,5,7,14,15 });
	switches.push_back(vector<int>{ 1,2,3,4,5 });
	switches.push_back(vector<int>{ 3,4,5,9,13 });
	int t;
	cin >> t;
	while (t--) {
		vector<int> clocks(CLOCKS);
		for (int i = 0; i < CLOCKS; i++) {
			cin >> clocks[i];
		}
		int res = go(clocks, 0);
		cout << (res >= INF ? -1 : res) << '\n';
	}

	return 0;
}
*/
#include <iostream>
#include <vector>
using namespace std;
const int INF = 9999, CLOCKS = 16, SWITCHES = 10;
const char linked[SWITCHES][CLOCKS + 1] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};
void push(vector<int>& clocks, int swtch) {
	for (int clock = 0; clock < CLOCKS; clock++) {
		if (linked[swtch][clock] == 'x') {
			clocks[clock] += 3;
			if (clocks[clock] == 15) clocks[clock] = 3;
		}
	}
}
bool areAligned(vector<int>& clocks) {
	for (int i = 0; i < CLOCKS; i++) {
		if (clocks[i] != 12) return false;
	}
	return true;
}
int go(vector<int>& clocks, int swtch) {
	if (swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;
	int ret = INF;
	for (int cnt = 0; cnt < 4; cnt++) {
		ret = min(ret, cnt + go(clocks, swtch + 1));
		push(clocks, swtch);
	}
	return ret;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		vector<int> clocks(CLOCKS);
		for (int i = 0; i < CLOCKS; i++) {
			cin >> clocks[i];
		}
		int res = go(clocks, 0);
		cout << (res >= INF ? -1 : res) << '\n';
	}


	return 0;
}