#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int d[100001][2];
int solution(vector<int> sticker)
{
    int answer = 0;
    int n = sticker.size();
    if (n == 1) return sticker[0];
    d[0][0] = sticker[0];
    d[1][1] = sticker[1];
    for (int i = 2; i < n; i++) {
        int num = sticker[i];
        for (int j = 0; j < 2; j++) {
            d[i][j] = max(d[i - 2][j] + num, d[i - 1][j]);
        }
    }
    answer = max(d[n - 1][1], max(d[n - 2][0], d[n - 2][1]));

    return answer;
}