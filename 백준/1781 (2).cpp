#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> ramens[200001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int deadline, ramen;
		cin >> deadline >> ramen;
		ramens[deadline].push_back(ramen);
	}

	int answer = 0;
	priority_queue<int> pq;
	for (int day = n; day >= 1; day--) {
		for (int ramen : ramens[day]) {
			pq.push(ramen);
		}
		if (!pq.empty()) {
			answer += pq.top();
			pq.pop();
		}
	}
	cout << answer << '\n';

	return 0;
}