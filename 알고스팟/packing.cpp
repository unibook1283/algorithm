#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
string name[101];
int volume[101], need[101];
int cache[1001][101];
int n, w;
int go(int capacity, int index) {
	if (index == n) return 0;
	int& ret = cache[capacity][index];
	if (ret != -1) return ret;
	ret = max(ret, go(capacity, index + 1));
	if (capacity - volume[index] >= 0)
		ret = max(ret, go(capacity - volume[index], index + 1) + need[index]);
	return ret;
}
void reconstruct(int capacity, int index, vector<string>& picked) {
	if (index == n) return;
	if (go(capacity, index) == go(capacity, index + 1))
		reconstruct(capacity, index + 1, picked);
	else {
		picked.push_back(name[index]);
		reconstruct(capacity - volume[index], index + 1, picked);
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		cin >> n >> w;
		for (int i = 0; i < n; i++) {
			cin >> name[i] >> volume[i] >> need[i];
		}
		cout << go(w, 0) << ' ';
		vector<string> picked;
		reconstruct(w, 0, picked);
		cout << picked.size() << '\n';
		for (string s : picked)
			cout << s << '\n';
	}

	return 0;
}