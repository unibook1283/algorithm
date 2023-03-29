#include <iostream>
#include <string>
#include <vector>

using namespace std;

int len;
int minMoves = 987654321;
int getLeftOfHere(int here, vector<bool> indexes) {
    int left = here;
    while (1) {
        left = (left + len - 1) % len;
        if (indexes[left]) {
            break;
        }
        if (left == here) { // 하나도 없어서 제자리로 다시 돌아온 경우
            break;
        }
    }
    if (left == here) return -1;
    return left;
}
int getRightOfHere(int here, vector<bool> indexes) {
    int right = here;
    while (1) {
        right = (right + 1) % len;
        if (indexes[right]) {
            break;
        }
        if (right == here) { // 하나도 없어서 제자리로 다시 돌아온 경우
            break;
        }
    }
    if (right == here) return -1;
    return right;
}
bool isFInished(vector<bool> indexes) {
    for (int i = 0; i < len; i++) {
        if (indexes[i]) return false;
    }
    return true;
}
void dfs(int here, vector<bool> indexes, int moves) {
    if (isFInished(indexes)) {
        minMoves = min(minMoves, moves);
        return;
    }
    int left = getLeftOfHere(here, indexes);
    int dist;
    if (left != -1) {
        if (left < here)
            dist = here - left;
        else
            dist = here + len - left;
        indexes[left] = false;
        dfs(left, indexes, moves + dist);
        indexes[left] = true;
    }

    int right = getRightOfHere(here, indexes);
    if (right != -1) {
        if (here < right)
            dist = right - here;
        else
            dist = right + len - here;
        indexes[right] = false;
        dfs(right, indexes, moves + dist);
        indexes[right] = true;
    }
}
int getUpDownCount(string name) {
    int ret = 0;
    for (int i = 0; i < name.length(); i++) {
        char ch = name[i];
        ret += min(ch - 'A', 'A' + 26 - ch);
    }
    return ret;
}
int solution(string name) {
    int answer = 0;
    len = name.length();
    vector<bool> indexes(len);

    for (int i = 0; i < len; i++) {
        if (name[i] != 'A') {
            indexes[i] = true;
        }
    }

    indexes[0] = false;
    dfs(0, indexes, 0);

    int upDownCount = getUpDownCount(name);

    answer = minMoves + upDownCount;

    return answer;
}