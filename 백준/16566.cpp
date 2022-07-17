#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> cards(m);
	vector<bool> check(m);
	for (int i = 0; i < m; i++) {
		cin >> cards[i];
	}
	sort(cards.begin(), cards.end());


	for (int i = 0; i < k; i++) {
		int cheolsu;
		cin >> cheolsu;
		int left = 0, right = m - 1;
		int m_index = 987654321;	// 민수가 낼 카드 번호의 인덱스
		while (left <= right) {
			int mid = (left + right) / 2;
			if (cards[mid] > cheolsu) {
				m_index = min(m_index, mid);
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		for (int i = m_index; i < m; i++) {
			if (!check[i]) {
				check[i] = true;
				cout << cards[i] << '\n';
				break;
			}
		}
		
	}

	return 0;
}