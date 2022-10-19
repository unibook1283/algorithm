#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    map<char, int> m;
    for (int i = 0; i < X.length(); i++) {
        m[X[i]]++;
    }
    for (int i = 0; i < Y.length(); i++) {
        if (m[Y[i]] > 0) {
            m[Y[i]]--;
            answer += Y[i];
        }
    }
    sort(answer.begin(), answer.end(), greater<>());
    if (answer == "") answer = "-1";
    else if (answer.front() == '0') answer = "0";
    return answer;
}