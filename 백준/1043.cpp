#include <iostream>
#include <vector>
using namespace std;
vector<int> parent(51);
vector<int> know_truth(51);
vector<int> party[51];
int getParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}
void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x < y) parent[y] = x;
	else parent[x] = y;
}
int checkSameParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x == y) return 1;
	return 0;
}
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> know_truth[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			int a;
			cin >> a;
			party[i].push_back(a);
		}
	}

	for (int i = 0; i < m; i++) {
		int node1 = party[i][0];
		for (int j = 1; j < party[i].size(); j++) {
			int node2 = party[i][j];
			unionParent(node1, node2);
		}
	}
	
	int ans = m;
	for (int i = 0; i < m; i++) {
		bool true_party = false;
		for (int j = 0; j < party[i].size(); j++) {
			for (int k = 0; k < know_truth.size(); k++) {
				if (checkSameParent(party[i][j], know_truth[k])) {
					true_party = true;
					break;
				}
			}
			if (true_party) break;
		}
		if (true_party) ans--;
	}
	cout << ans << '\n';


	return 0;
}