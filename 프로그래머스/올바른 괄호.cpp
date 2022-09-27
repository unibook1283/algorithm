#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            cnt++;
        }
        else {
            if (cnt == 0) {
                answer = false;
                break;
            }
            cnt--;
        }
    }
    if (cnt != 0) answer = false;
    return answer;
}