#include <iostream>
#include <queue>
using namespace std;
int n, x;
int a[100001];
int getTotalTime(int line) {
	priority_queue<int> pq;
	for (int i = 0; i < min(n, line); i++) {
		pq.push(-a[i]);
	}

	for (int i = line; i < n; i++) {
		int x = -pq.top();
		pq.pop();
		pq.push(-(x + a[i]));
	}

	while (pq.size() != 1) {
		pq.pop();
	}

	return -pq.top();
}
int main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int left = 1, right = 100000;
	int answer = 100000;
	while (left <= right) {
		int mid = (left + right) / 2;
		int totalTime = getTotalTime(mid);
		if (totalTime <= x) {
			answer = min(answer, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << answer << '\n';

	return 0;
}