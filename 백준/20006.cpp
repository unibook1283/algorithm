#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int p, m;
	cin >> p >> m;
	vector<vector<pair<string, int>>> room;	// (닉네임, 레벨)
	for (int i = 0; i < p; i++) {
		int l;
		string n;
		cin >> l >> n;
		pair<string, int> player = make_pair(n, l);

		bool enter = false;
		for (int i = 0; i < room.size(); i++) {
			if (room[i].size() == m) continue;
			int room_level = room[i][0].second;
			if (room_level - 10 <= l && l <= room_level + 10) {
				room[i].push_back(player);
				enter = true;
				break;
			}
		}
		if (!enter) {
			vector<pair<string, int>> r;
			r.push_back(player);
			room.push_back(r);
		}
	}

	for (int i = 0; i < room.size(); i++) {
		sort(room[i].begin(), room[i].end());
	}

	for (int i = 0; i < room.size(); i++) {
		if (room[i].size() == m) cout << "Started!\n";
		else cout << "Waiting!\n";
		for (int j = 0; j < room[i].size(); j++) {
			cout << room[i][j].second << ' ' << room[i][j].first << '\n';
		}
	}

	return 0;
}