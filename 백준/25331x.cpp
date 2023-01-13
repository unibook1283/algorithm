#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int original_map[7][7];
int map[7][7];
void copy_map() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			map[i][j] = original_map[i][j];
		}
	}
}
void fall_the_ball_at_column(int col, int ball) {
	for (int i = 6; i >= 0; i--) {
		if (map[i][col] == 0) {
			map[i][col] = ball;
			break;
		}
	}
}
void get_row_count(vector<vector<int>>& row_count) {
	for (int i = 0; i < 7; i++) {
		int cnt = 0;
		vector<int> r;
		for (int j = 0; j < 7; j++) {
			if (map[i][j] == 0) {
				if (cnt != 0) {
					r.push_back(cnt);
					cnt = 0;
				}
			}
			else {
				cnt++;
			}
		}
		if (cnt != 0) r.push_back(cnt);
		row_count.push_back(r);
	}
}
void get_col_count(vector<vector<int>>& col_count) {
	for (int i = 0; i < 7; i++) {
		int cnt = 0;
		vector<int> c;
		for (int j = 0; j < 7; j++) {
			if (map[j][i] == 0) {
				if (cnt != 0) {
					c.push_back(cnt);
					cnt = 0;
				}
			}
			else {
				cnt++;
			}
		}
		if (cnt != 0) c.push_back(cnt);
		col_count.push_back(c);
	}
}
void find_row_delete_balls(vector<pair<int, int>>& delete_balls, vector<vector<int>> row_count) {
	for (int i = 0; i < 7; i++) {
		int vector_index = 0;
		bool start = false;
		for (int j = 0; j < 7; j++) {
			if (vector_index == row_count[i].size()) break;
			if (map[i][j] == row_count[i][vector_index])
				delete_balls.push_back(make_pair(i, j));
			if (map[i][j] != 0) start = true;
			else if (start) vector_index++;
		}
	}
}
void find_col_delete_balls(vector<pair<int, int>>& delete_balls, vector<vector<int>> col_count) {
	for (int i = 0; i < 7; i++) {
		int vector_index = 0;
		bool start = false;
		for (int j = 0; j < 7; j++) {
			if (vector_index == col_count[i].size()) break;
			if (map[j][i] == col_count[i][vector_index])
				delete_balls.push_back(make_pair(j, i));
			if (map[j][i] != 0) start = true;
			else if (start) vector_index++;
		}
	}
}
void delete_ball(int x, int y) {
	while (x - 1 >= 0) {
		map[x][y] = map[x - 1][y];
		x--;
	}
	if (x == 0) map[x][y] = 0;
}
int count_left_balls() {
	int count = 0;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			if (map[i][j] != 0) count++;
	return count;
}
int main() {
	int cnt = 0;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			cin >> original_map[i][j];
	int n;
	cin >> n;

	int ans = 987654321;
	for (int i = 0; i < 7; i++) {
		copy_map();
		fall_the_ball_at_column(i, n);
		while (1) {
			vector<vector<int>> row_count, col_count;
			get_row_count(row_count);
			get_col_count(col_count);

			vector<pair<int, int>> delete_balls;
			find_row_delete_balls(delete_balls, row_count);
			find_col_delete_balls(delete_balls, col_count);
			if (delete_balls.empty()) break;
			sort(delete_balls.begin(), delete_balls.end());
			delete_balls.erase(unique(delete_balls.begin(), delete_balls.end()), delete_balls.end());
			for (int i = 0; i < delete_balls.size(); i++) {
				int x = delete_balls[i].first;
				int y = delete_balls[i].second;
				delete_ball(x, y);
			}
		}
		int left = count_left_balls();
		ans = min(ans, left);
	}
	cout << ans << '\n';

	return 0;
}