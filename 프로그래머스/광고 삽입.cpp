#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
int convert(string time) {
    stringstream ss(time);
    int h, m, s;
    char ch;
    ss >> h >> ch >> m >> ch >> s;
    return h * 60 * 60 + m * 60 + s;
}
string solution(string play_time, string adv_time, vector<string> logs) {
    int playSec = convert(play_time);
    int advSec = convert(adv_time);

    int totalSec[100 * 60 * 60] = { 0 };
    for (string log : logs) {
        int from = convert(log.substr(0, 8));
        int to = convert(log.substr(9));
        for (int i = from; i < to; i++) {
            totalSec[i]++;
        }
    }

    long long currSum = 0;
    for (int i = 0; i < advSec; i++) {
        currSum += totalSec[i];
    }

    long long maxSum = currSum;
    int maxIdx = 0;
    for (int i = advSec; i < playSec; i++) {
        currSum += totalSec[i] - totalSec[i - advSec];
        if (currSum > maxSum) {
            maxSum = currSum;
            maxIdx = i - advSec + 1;
        }
    }

    char buf[10];
    sprintf(buf, "%02d:%02d:%02d", maxIdx / 60 / 60, maxIdx / 60 % 60, maxIdx % 60);
    string answer = buf;

    return answer;
}