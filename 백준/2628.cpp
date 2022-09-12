#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int k;
	cin >> k;
	vector<int> h;
	vector<int> v;
	for (int i = 0; i < k; i++) {
		int vh, num;
		cin >> vh >> num;
		if (vh == 0) h.push_back(num);
		else v.push_back(num);
	}
	sort(h.begin(), h.end());
	sort(v.begin(), v.end());
	
	int hmax = 0, vmax = 0;
	int prev = 0;
	for (int i = 0; i < h.size(); i++) {
		hmax = max(hmax, h[i] - prev);
		prev = h[i];
	}
	hmax = max(hmax, m - prev);

	prev = 0;
	for (int i = 0; i < v.size(); i++) {
		vmax = max(vmax, v[i] - prev);
		prev = v[i];
	}
	vmax = max(vmax, n - prev);

	cout << vmax * hmax << '\n';

	return 0;
}