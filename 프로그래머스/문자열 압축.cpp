#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();
    for (int i = 1; i <= s.length() / 2; i++) {
        int pos = 0;
        int len = s.length();

        while (1) {
            string unit = s.substr(pos, i);
            pos += i;

            if (pos >= s.length()) break;

            int cnt = 1;
            while (1) {
                if (unit == s.substr(pos, i)) {
                    cnt++;
                    pos += i;
                }
                else break;
            }
            if (cnt > 1) {
                len -= i * (cnt - 1);

                if (cnt < 10) len++;
                else if (cnt < 100) len += 2;
                else if (cnt < 1000) len += 3;
                else len += 4;
            }
        }
        answer = min(answer, len);
    }

    return answer;
}