#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int T1, T2, A, B, outside_temperature, dt;
vector<int> ONBOARD;
int cache[1001][51];
int go(int index, int temperature) {
    if (index == ONBOARD.size()) {
        return 0;
    }
    if (ONBOARD[index]) {
        if (temperature < T1 || T2 < temperature) return 987654321;
    }
    int& ret = cache[index][temperature + 10];
    if (ret != -1) return ret;
    ret = 987654321;
    // 에어컨의 희망온도와 실내온도가 다를 때 에어컨 on
    ret = min(ret, A + go(index + 1, temperature + dt));
    // 에어컨의 희망온도와 실내온도가 같을 때 에어컨 on
    ret = min(ret, B + go(index + 1, temperature));
    // 에어컨 off
    if (dt == 1)
        ret = min(ret, go(index + 1, max(temperature - dt, outside_temperature)));
    else
        ret = min(ret, go(index + 1, min(temperature - dt, outside_temperature)));
    return ret;
}
int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    T1 = t1; T2 = t2; A = a; B = b; outside_temperature = temperature;
    ONBOARD = onboard;
    dt = temperature < t1 ? +1 : -1;
    memset(cache, -1, sizeof(cache));
    return go(0, temperature);
}