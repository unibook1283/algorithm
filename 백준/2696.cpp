#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int m;
		cin >> m;
		vector<int> answer;
		priority_queue<int> max_heap;
		priority_queue<int, vector<int>, greater<int>> min_heap;
		for (int i = 1; i <= m; i++) {
			int num;
			cin >> num;
			// 일단 queue에 삽입
			if (max_heap.size() == min_heap.size())
				max_heap.push(num);
			else
				min_heap.push(num);
			// 크기에 맞게 재조정
			if (!max_heap.empty() && !min_heap.empty()
				&& max_heap.top() > min_heap.top()) {
				int max_top = max_heap.top();
				max_heap.pop();
				int min_top = min_heap.top();
				min_heap.pop();
				max_heap.push(min_top);
				min_heap.push(max_top);
			}
			if (i % 2 == 1) {
				answer.push_back(max_heap.top());
			}
		}
		cout << answer.size() << '\n';
		for (int i = 0; i < answer.size(); i++) {
			if (i != 0 && i % 10 == 0)
				cout << '\n'; 
			cout << answer[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}