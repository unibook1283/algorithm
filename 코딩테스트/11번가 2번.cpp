// you can use includes, for example:
// #include <algorithm>
#include <iostream>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using namespace std;

int go(int index, string S, int open) {
    if (index == S.length()) {
        return 0;
    }
    int ret = 0;
    if (S[index] != '<') {
        if (open == 0)
            ret = max(ret, go(index + 1, S, 0));
        else
            if (index + 1 < S.length() && S[index + 1] == '<')
                ret = max(ret, go(index + 1, S, open - 1));
            else
                ret = max(ret, 2 + go(index + 1, S, open - 1));
    }
    if (S[index] != '>') {
        ret = max(ret, go(index + 1, S, open + 1));
    }
    return ret;
}
int solution(string& S) {
    // Implement your solution here
    return go(0, S, 0);
}
/*
메모이제이션 쓰려했는데, cache[200001][200001] 크기가 안되네.
미리 예상했어야 하는 부분.
*/