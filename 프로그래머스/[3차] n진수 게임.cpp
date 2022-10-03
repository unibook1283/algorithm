#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string to_n(int num, int n, vector<char> map) {
    if (num == 0) return "0";
    string ret;
    while (num > 0) {
        ret += map[num % n];
        num /= n;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
string solution(int n, int t, int m, int p) {
    string answer = "";

    vector<char> map(16);
    for (int i = 0; i < 10; i++) {
        map[i] = '0' + i;
    }
    for (int i = 10; i < 16; i++) {
        map[i] = 'A' + i - 10;
    }

    string temp;
    for (int i = 0; i < 100000; i++) {
        temp += to_n(i, n, map);
    }
    for (int i = 0; i < t; i++) {
        answer += temp[m * i + p - 1];
    }

    return answer;
}