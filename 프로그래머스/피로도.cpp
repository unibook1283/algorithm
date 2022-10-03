#include <string>
#include <vector>

using namespace std;
bool check[10];
int answer = 0;
void go(int cnt, int k, vector<vector<int>> dungeons) {
    answer = max(answer, cnt);
    int n = dungeons.size();
    for (int i = 0; i < n; i++) {
        int l_fatigue = dungeons[i][0];
        int c_fatigue = dungeons[i][1];
        if (check[i] || k < l_fatigue) continue;
        check[i] = true;
        go(cnt + 1, k - c_fatigue, dungeons);
        check[i] = false;
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    go(0, k, dungeons);

    return answer;
}