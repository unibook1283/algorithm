#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int id_seq[500];
int like[500][4];
int map[21][21];
int n;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int like_friend_count(int id, int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			int adj_id = map[nx][ny];
			for (int j = 0; j < 4; j++) {
				if (adj_id == like[id][j]) cnt++;
			}
		}
	}
	return cnt;
}
int cal_adj_empty_cnt(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (map[nx][ny] == 0) cnt++;
		}
	}
	return cnt;
}
vector<pair<pair<int, int>, int>> first_condition(int id) {
	int max_like_friend = 0;
	vector<pair<pair<int, int>, int>> ret;	//(x, y, 인접한 칸 중에서 비어있는 칸의 개수)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				int like_friend = like_friend_count(id, i, j);
				int adj_empty = cal_adj_empty_cnt(i, j);
				if (like_friend == max_like_friend)
					ret.push_back(make_pair(make_pair(i, j), adj_empty));
				else if (like_friend > max_like_friend) {
					ret.clear();
					ret.push_back(make_pair(make_pair(i, j), adj_empty));
					max_like_friend = like_friend;
				}
			}
		}
	}
	return ret;
}
vector<pair<int, int>> second_condition(vector<pair<pair<int, int>, int>> cand) {
	vector<pair<int, int>> ret;
	int max_adj_empty_cnt = 0;
	for (int i = 0; i < cand.size(); i++) {
		int adj_empty_cnt = cand[i].second;
		if (adj_empty_cnt == max_adj_empty_cnt) {
			ret.push_back(cand[i].first);
		}
		else if (adj_empty_cnt > max_adj_empty_cnt) {
			ret.clear();
			ret.push_back(cand[i].first);
			max_adj_empty_cnt = adj_empty_cnt;
		}
	}
	return ret;
}
pair<int, int> third_condition(vector<pair<int, int>> cand) {
	sort(cand.begin(), cand.end());
	return cand[0];
}
void sit_down(pair<int, int> seat, int id) {
	int x = seat.first;
	int y = seat.second;
	map[x][y] = id;
}
int get_satisfaction(int adj_like_count) {
	if (adj_like_count == 0) return 0;
	else if (adj_like_count == 1) return 1;
	else if (adj_like_count == 2) return 10;
	else if (adj_like_count == 3) return 100;
	else if (adj_like_count == 4) return 1000;
}
int total_satisfaction() {
	int total_satisfaction = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int id = map[i][j];
			int adj_like_count = like_friend_count(id, i, j);
			int satisfaction = get_satisfaction(adj_like_count);
			total_satisfaction += satisfaction;
		}
	}
	return total_satisfaction;
}
int main() {
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		cin >> id_seq[i];
		for (int j = 0; j < 4; j++) {
			cin >> like[id_seq[i]][j];
		}
	}

	for (int i = 0; i < n * n; i++) {
		int id = id_seq[i];
		vector<pair<pair<int, int>, int>> cand;
		cand = first_condition(id);
		if (cand.size() == 1) {
			sit_down(cand[0].first, id);
			continue;
		}
		vector<pair<int,int>> cand2 = second_condition(cand);
		if (cand2.size() == 1) {
			sit_down(cand2[0], id);
			continue;
		}
		pair<int, int> seat = third_condition(cand2);
		sit_down(seat, id);
	}
	int ans = total_satisfaction();
	cout << ans << '\n';

	return 0;
}