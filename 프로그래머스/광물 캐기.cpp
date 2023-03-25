#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int answer = 987654321;
map<string, int> m;
int stressArray[3][3] = {
    {1,1,1},
    {5,1,1},
    {25,5,1}
};
int mineMineralWithPickaxe(int pick, int cnt, vector<string> minerals) {
    int ret = 0;
    for (int i = cnt * 5; i < cnt * 5 + 5; i++) {
        if (i == minerals.size()) break;
        ret += stressArray[pick][m[minerals[i]]];
    }
    return ret;
}
bool finishCheck(int cnt, vector<int> picks, int totalMineral) {
    if (cnt * 5 >= totalMineral) return true;
    for (int i = 0; i < picks.size(); i++) {
        if (picks[i] != 0) return false;
    }
    return true;
}
void go(int cnt, int stress, vector<int> picks, vector<string> minerals) {
    if (finishCheck(cnt, picks, minerals.size())) {
        answer = min(answer, stress);
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (picks[i] > 0) {
            int getStress = mineMineralWithPickaxe(i, cnt, minerals);
            picks[i]--;
            go(cnt + 1, stress + getStress, picks, minerals);
            picks[i]++;
        }
    }
}
int solution(vector<int> picks, vector<string> minerals) {
    m["diamond"] = 0;
    m["iron"] = 1;
    m["stone"] = 2;

    go(0, 0, picks, minerals);

    return answer;
}