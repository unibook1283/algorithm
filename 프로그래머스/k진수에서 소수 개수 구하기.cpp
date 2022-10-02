#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool is_prime(long long n) {
    if (n == 1) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    string s;
    while (n > 0) {
        s += to_string(n % k);
        n /= k;
    }
    reverse(s.begin(), s.end());

    vector<long long> v;
    string temp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            if (temp == "") continue;
            v.push_back(stoll(temp));
            temp = "";
        }
        else {
            temp += s[i];
        }
    }
    if (temp != "") v.push_back(stoll(temp));

    for (int i = 0; i < v.size(); i++) {
        if (is_prime(v[i])) answer++;
    }

    return answer;
}
/*
long long인데 stoi를 써서 한참 헤맸네.
stoll을 써야됨.
*/