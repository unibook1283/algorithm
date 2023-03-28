#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1000001;
int d[MAX];
int solution(int x, int y, int n) {
    int answer = -1;
    memset(d, -1, sizeof(d));
    d[x] = 0;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == y) {
            answer = d[cur];
            break;
        }
        int next = cur + n;
        if (next < MAX && d[next] == -1) {
            d[next] = d[cur] + 1;
            q.push(next);
        }
        for (int i = 2; i <= 3; i++) {
            next = cur * i;
            if (next < MAX && d[next] == -1) {
                d[next] = d[cur] + 1;
                q.push(next);
            }
        }
    }

    return answer;
}