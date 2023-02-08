#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct Room {
	char ch;
	int money;
	vector<int> v;
};
vector<Room> rooms;
int n;
bool check[1001];
bool dfs(int index, int money) {
	Room room = rooms[index];
	if (room.ch == 'L') {
		money = max(money, room.money);
	}
	else if (room.ch == 'T') {
		if (money < room.money) return false;
		money -= room.money;
	}
	if (index == n - 1) return true;
	for (int i = 0; i < room.v.size(); i++) {
		if (!check[room.v[i]]) {
			check[room.v[i]] = true;
			if (dfs(room.v[i], money))
				return true;
			check[room.v[i]] = false;
		}
	}
	return false;
}
int main() {
	while (1) {
		rooms.clear();
		memset(check, false, sizeof(check));
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			char ch;
			int money;
			cin >> ch >> money;
			vector<int> v;
			while (1) {
				int x;
				cin >> x;
				if (x == 0) break;
				x--;
				v.push_back(x);
			}
			Room room;
			room.ch = ch;
			room.money = money;
			room.v = v;
			rooms.push_back(room);
		}
		check[0] = true;
		if (dfs(0, 0))
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}