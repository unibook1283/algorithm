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
        // ���⸦ �߰��ϴϱ� �³�.
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
�׽�Ʈ ���̽��� 5, [3,3,3,3] ���� �ϰ� �غ��ø� �˴ϴ�.
��� �ο��� 3�ܰ迡�� ������ ���, 4,5 �ܰ��� �������� 0.0�� �Ǿ� �ϴµ�
�и� ���� ���� �� �� �س��� ��� 0/0 �� �ǹ�����, Nan���� ���� ���� ��� �����մϴ�.
*/