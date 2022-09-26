#include <string>
#include <vector>

using namespace std;
string reverse(string s) {
    string res;
    for (int i = s.length() - 1; i >= 0; i--) {
        res += s[i];
    }
    return res;
}
string make_string(int x) {
    string s;
    while (x != 1) {
        s += to_string(x % 2);
        x /= 2;
    }
    s += '1';
    return reverse(s);
}
vector<int> solution(string s) {
    vector<int> answer;

    int trans_cnt = 0;
    int zero_cnt = 0;
    while (s != "1") {
        trans_cnt++;
        for (int i = 0; i < s.length();) {
            if (s[i] == '0') {
                s.erase(i, 1);
                zero_cnt++;
            }
            else {
                i++;
            }
        }
        int x = s.length();
        s = make_string(x);
    }
    answer.push_back(trans_cnt);
    answer.push_back(zero_cnt);

    return answer;
}