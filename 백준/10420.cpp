#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int thirty_one[] = { 1,3,5,7,8,10,12 };
int thirty[]  = { 4,6,9,11 };
bool check_thirty_one(int month) {
	for (int i = 0; i < 7; i++) {
		if (thirty_one[i] == month) return true;
	}
	return false;
}
bool check_thirty(int month) {
	for (int i = 0; i < 4; i++) {
		if (thirty[i] == month) return true;
	}
	return false;
}
bool check_yoonnyeon(int year) {
	if (year % 400 == 0) return true;
	else if (year % 100 == 0) return false;
	else if (year % 4 == 0) return true;
	else return false;
}
int main() {
	int year = 2014;
	int month = 4;
	int day = 2;

	int n;
	scanf("%d", &n);
	while (--n) {
		day++;
		if (day == 32 && check_thirty_one(month)){

			day = 1;
			month++;
			if (month == 13) {
				year++;
				month = 1;
			}
		}
		else if (day == 31 && check_thirty(month)) {
			day = 1;
			month++;
		}
		else if (month == 2 && day == 29 && !check_yoonnyeon(year)) {
			day = 1;
			month++;
		}
		else if (month == 2 && day == 30 && check_yoonnyeon(year)) {
			day = 1;
			month++;
		}
	}
	printf("%04d-%02d-%02d", year, month, day);

	return 0;
}