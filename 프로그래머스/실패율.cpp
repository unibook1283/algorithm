#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int a[510];
bool cmp(pair<double, int> &u, pair<double, int> &v) {
    if (u.first == v.first) 
        return u.second < v.second;
    return u.first > v.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> fail_rate(N);

    int triers = stages.size();
    for (int i = 0; i < triers; i++) {
        a[stages[i]]++;
    }
    for (int i = 0; i < N; i++) {
        // 여기를 추가하니까 맞네.
        if (a[i + 1] == 0) {
            fail_rate[i] = make_pair(0, i + 1);
            continue;
        }
        //
        fail_rate[i] = make_pair(a[i + 1] / (double)triers, i + 1);
        triers -= a[i + 1];
    }
    sort(fail_rate.begin(), fail_rate.end(), cmp);
    for (int i = 0; i < N; i++) {
        answer.push_back(fail_rate[i].second);
    }

    return answer;
}
int main() {
    
    vector<int> v = { 3, 3, 3, 3 };
    vector<int> ans = solution(5, v);
    for (int i = 0; i < 5; i++) {
        cout << ans[i] << '\n';
    }
    int a = 0;
    cout << a / (float)0;
    return 0;
}
/*
테스트 케이스를 5, [3,3,3,3] 으로 하고 해보시면 됩니다.
모든 인원이 3단계에서 실패한 경우, 4,5 단계의 실패율은 0.0이 되야 하는데
분모를 남은 유저 수 로 해놓은 경우 0/0 이 되버려서, Nan으로 값이 잡혀 계속 실패합니다.
*/