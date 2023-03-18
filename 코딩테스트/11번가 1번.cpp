// you can use includes, for example:
// #include <algorithm>
#include <iostream>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using namespace std;

int alphaCnt[26];
int solution(string& S) {
    // Implement your solution here
    for (char ch : S) {
        alphaCnt[ch - 'a']++;
    }

    int answer = 0;
    for (int i = 0; i < 26; i++) {
        if (alphaCnt[i] % 2 != 0)
            answer++;
    }

    return answer;
}