#include <iostream>
#include <vector>
using namespace std;
typedef struct Room {
	long long t, a, h;
};
const long long MAX = 1e18;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long n, atk_init;
	cin >> n >> atk_init;
	vector<Room> rooms(n);
	for (int i = 0; i < n; i++) {
		cin >> rooms[i].t >> rooms[i].a >> rooms[i].h;
	}

	long long left = 1, right = MAX;
	long long answer = -1;
	while (left <= right) {
		long long mid = (left + right) / 2;	// max_hp
		long long curr_hp = mid;
		long long curr_atk = atk_init;
		bool win = true;
		for (int i = 0; i < n; i++) {
			long long t = rooms[i].t;
			long long a = rooms[i].a;
			long long h = rooms[i].h;
			if (t == 1) {
				if ((h - 1) / curr_atk > (curr_hp  - 1) / a) {
					win = false;
					break;
				}
				curr_hp -= (h - 1) / curr_atk * a;
			}
			else {
				curr_atk += a;
				curr_hp = min(curr_hp + h, mid);
			}
		}
		if (win) {
			answer = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	
	cout << answer << '\n';

	return 0;
}