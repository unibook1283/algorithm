#include <string>
#include <vector>
#include <cstring>
using namespace std;
long long check[2001];
long long go(long long sum, int n) {
    if (sum == n) return 1;
    if (sum == n + 1) return 0;
    long long &ret = check[sum];
    if (ret != -1) return ret;
    return ret = (go(sum + 1, n) + go(sum + 2, n)) % 1234567;
}
long long solution(int n) {
    memset(check, -1, sizeof(check));
    return go(0, n) % 1234567;
}