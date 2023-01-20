#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int a[100001];
bool visited[100001];
bool finished[100001];
int ans = 0;
void go(int cur) {
	visited[cur] = true;
	int next = a[cur];
	if (!visited[next]) {
		go(next);
	}
	else {
		if (!finished[next]) {
			for (int i = next; i != cur; i = a[i]) {
				ans++;
			}
			ans++;
		}
	}
	finished[cur] = true;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		ans = 0;
		memset(visited, false, sizeof(visited));
		memset(finished, false, sizeof(finished));
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		
		for (int i = 1; i <= n; i++) {
			if (!visited[i])
				go(i);
		}
		cout << n - ans << '\n';
	}

	return 0;
}