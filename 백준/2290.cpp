#include <iostream>
#include <vector>
using namespace std;
int s;
int a[10][7] = {			// index of 7segment
	{1,1,1,0,1,1,1},		//	0
	{0,0,1,0,0,1,0},		// 1 2
	{1,0,1,1,1,0,1},		//  3
	{1,0,1,1,0,1,1},		// 4 5
	{0,1,1,1,0,1,0},		//  6
	{1,1,0,1,0,1,1},
	{1,1,0,1,1,1,1},
	{1,0,1,0,0,1,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1},
};
void zero(vector<string>& v, int num) {
	v[0].push_back(' ');
	for (int i = 0; i < s; i++) {
		if (a[num][0] == 1) {
			v[0].push_back('-');
		}
		else {
			v[0].push_back(' ');
		}
	}
	v[0].push_back(' ');
}
void one(vector<string>& v, int num) {
	for (int i = 1; i < 1 + s; i++) {
		if (a[num][1] == 1) {
			v[i].push_back('|');
		}
		else {
			v[i].push_back(' ');
		}
		for (int j = 0; j < s; j++) {
			v[i].push_back(' ');
		}
	}
}
void two(vector<string>& v, int num) {
	for (int i = 1; i < 1 + s; i++) {
		if (a[num][2] == 1) {
			v[i].push_back('|');
		}
		else {
			v[i].push_back(' ');
		}
	}
}
void three(vector<string>& v, int num) {
	v[s + 1].push_back(' ');
	for (int i = 0; i < s; i++) {
		if (a[num][3] == 1) {
			v[s + 1].push_back('-');
		}
		else {
			v[s + 1].push_back(' ');
		}
	}
	v[s + 1].push_back(' ');
}
void four(vector<string>& v, int num) {
	for (int i = s + 2; i < 2 * s + 2; i++) {
		if (a[num][4] == 1) {
			v[i].push_back('|');
		}
		else {
			v[i].push_back(' ');
		}
		for (int j = 0; j < s; j++) {
			v[i].push_back(' ');
		}
	}
}
void five(vector<string>& v, int num) {
	for (int i = s + 2; i < 2 * s + 2; i++) {
		if (a[num][5] == 1) {
			v[i].push_back('|');
		}
		else {
			v[i].push_back(' ');
		}
	}
}
void six(vector<string>& v, int num) {
	v[2 * s + 2].push_back(' ');
	for (int i = 0; i < s; i++) {
		if (a[num][6] == 1) {
			v[2 * s + 2].push_back('-');
		}
		else {
			v[2 * s + 2].push_back(' ');
		}
	}
	v[2 * s + 2].push_back(' ');
}
void insert_blank(vector<string>& v) {
	for (int i = 0; i < 2 * s + 3; i++) {
		v[i].push_back(' ');
	}
}
void insert_num(vector<string>& v, char num) {
	zero(v, num);
	one(v, num);
	two(v, num);
	three(v, num);
	four(v, num);
	five(v, num);
	six(v, num);
	insert_blank(v);
}
int main() {
	string n;
	cin >> s >> n;
	int height = 2 * s + 3;
	vector<string> v(height);
	
	int length = n.size();
	for (int i = 0; i < length; i++) {
		insert_num(v, n[i] - '0');
	}

	for (int i = 0; i < height; i++) {
		cout << v[i] << '\n';
	}

	return 0;
}