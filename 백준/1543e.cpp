#include <iostream>
#include <string>
using namespace std;
int main() {
	string s, search;
	getline(cin, s);
	getline(cin, search);
	int cnt = 0;
	int s1 = s.size();
	int s2 = search.size();
//	for (int i = 0; i <= s.size() - search.size(); i++) {
	for (int i = 0; i <= s1 - s2; i++) {
		bool found = true;
		for (int j = 0; j < search.size(); j++) {
			if (s[i + j] != search[j]) {
				found = false;
				break;
			}
		}
		if (found) {
			cnt++;
			i += search.size() - 1;
		}
	}
	cout << cnt;

	return 0;
}
/*
��Ÿ�� ����...

��, �ϳ� �����.
���ؿ� �����غ���
"s.size()-search.size()�� �����÷ο�� ���� 2^64�� ����� �ſ� ū ���� �� �� �ֽ��ϴ�."
��� ���� ����.
ã�ƺ��� .size()�� unsigned value�� return�ؼ�, .size()���� ���� ���� ������ ū ���� ���� ��쿡
0�� ���� ��û ū ���� �� �� �ִ� ����.
.size()�� return ���� int�� ������ �����ؼ� ���⸦ �����ϴ� ������� �ذ���.
https://stackoverflow.com/questions/32943287/subtracting-size-function-values-of-different-strings
*/