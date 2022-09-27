#include <string>
#include <vector>

using namespace std;
int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}
int lcm(int x, int y) {
    return x * y / gcd(x, y);
}
int solution(vector<int> arr) {
    int answer = 1;
    for (int i = 0; i < arr.size(); i++) {
        answer = lcm(answer, arr[i]);
    }
    return answer;
}