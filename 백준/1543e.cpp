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
런타임 에러...

와, 하나 배웠다.
백준에 질문해보니
"s.size()-search.size()가 오버플로우로 인해 2^64에 가까운 매우 큰 수가 될 수 있습니다."
라는 답을 들음.
찾아보니 .size()는 unsigned value를 return해서, .size()끼리 빼면 작은 수에서 큰 수를 빼는 경우에
0을 지나 엄청 큰 수가 될 수 있는 거임.
.size()의 return 값을 int형 변수에 저장해서 빼기를 실행하는 방법으로 해결함.
https://stackoverflow.com/questions/32943287/subtracting-size-function-values-of-different-strings
*/