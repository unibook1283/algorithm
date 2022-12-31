#include <iostream>
#include <string>
using namespace std;
int covert_string_to_second(string t) {
	int minute = stoi(t.substr(0, 2));
	int second = stoi(t.substr(3));
	return minute * 60 + second;
}
string convert_second_to_string(int second) {
	int minute = second / 60;
	second %= 60;

	string ret = "";
	if (minute < 10) ret += '0';
	ret += to_string(minute);
	ret += ':';
	if (second < 10) ret += '0';
	ret += to_string(second);
	return ret;
}
int main() {
	int n;
	cin >> n;

	int prev = 0;
	int score1 = 0, score2 = 0;
	int time1 = 0, time2 = 0;
	for (int i = 0; i < n; i++) {
		int team;
		string t;
		cin >> team >> t;
		int time = covert_string_to_second(t);
		if (score1 > score2)
			time1 += time - prev;
		else if (score1 < score2)
			time2 += time - prev;
		
		if (team == 1) score1++;
		else score2++;
		prev = time;
	}
	int end_time = 48 * 60;
	if (score1 > score2)
		time1 += end_time - prev;
	else if (score1 < score2)
		time2 += end_time - prev;

	cout << convert_second_to_string(time1) << '\n';
	cout << convert_second_to_string(time2) << '\n';

	return 0;
}