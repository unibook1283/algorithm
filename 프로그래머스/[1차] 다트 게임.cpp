#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    map<char, int> m;
    m['S'] = 1;
    m['D'] = 2;
    m['T'] = 3;
    m['*'] = 2;
    m['#'] = -1;
    int answer = 0;
    int num = 0;
    int v_index = -1;
    vector<int> v;
    for (int i = 0; i < dartResult.size(); i++) {
        char ch = dartResult[i];
        if ('0' <= ch && ch <= '9') {
            num = 10 * num + ch - '0';
        }
        else if (ch == 'S' || ch == 'D' || ch == 'T') {
            v.push_back(pow(num, m[ch]));
            v_index++;
            num = 0;
        }
        else if (ch == '*') {
            if (v_index - 1 >= 0) {
                v[v_index - 1] *= 2;
            }
            v[v_index] *= 2;
        }
        else if (ch == '#') {
            v[v_index] *= -1;
        }
    }
    for (int x : v) {
        answer += x;
    }

    return answer;
}