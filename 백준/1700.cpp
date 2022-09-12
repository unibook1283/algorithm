#include <iostream>
#include <vector>
using namespace std;
int a[101];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
	vector<int> plug(n);
	int ans = 0;
	for (int i = 0; i < k; i++) {
		bool flag = false;
		// 이미 플러그에 있는 경우
 		for (int j = 0; j < n; j++) {
			if (a[i] == plug[j]) {
				flag = true;
				break;
			}
		}
		if (flag) continue;
		// 플러그에 처음 꽂는 경우
		for (int j = 0; j < n; j++) {
			if (plug[j] == 0) {
				plug[j] = a[i];
				flag = true;
				break;
			}
		}
		if (flag) continue;
		// 플러그 하나를 빼야되는 경우
		int plug_index;
		int a_index = -1;
		for (int j = 0; j < n; j++) {
			int m;	// 해당 플러그가 사용되는 가장 가까운 미래 인덱스
			for (m = i + 1; m < k; m++) {
				if (plug[j] == a[m]) {
					break;
				}
			}
			if (a_index < m) {
				a_index = m;
				plug_index = j;
			}
		}
		plug[plug_index] = a[i];
		ans++;
	}
	cout << ans << '\n';

	return 0;
}