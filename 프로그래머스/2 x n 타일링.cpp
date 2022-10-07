#include <string>
#include <vector>

using namespace std;
int d[60001];
int solution(int n) {
    int answer = 0;
    d[0] = 1;
    d[1] = 1;
    for (int i = 2; i <= n; i++) {
        d[i] = (d[i - 2] + d[i - 1]) % 1000000007;
    }

    return d[n];
}