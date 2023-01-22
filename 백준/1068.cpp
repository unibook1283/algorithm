#include <iostream>
#include <vector>
using namespace std;
int a[51];
vector<int> v[51];
int removed;
int ans = 0;
void go(int x) {
	if (v[x].empty()) {
		ans++;
		return;
	}
	for (int i = 0; i < v[x].size(); i++)
		go(v[x][i]);
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> removed;

	int root;
	for (int i = 0; i < n; i++) {
		if (a[i] == -1) {
			root = i;
			continue;
		}
		if (i == removed) continue;
		v[a[i]].push_back(i);
	}
	if (root == removed) {
		cout << "0\n";
		return 0;
	}
	go(root);
	cout << ans << '\n';

	return 0;
}