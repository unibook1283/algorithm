#include <string>
#include <vector>

using namespace std;
string numbers[10] = {
    "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine"
};
int solution(string s) {
    int answer = 0;

    for (int i = 0; i < s.length();) {
        if ('0' <= s[i] && s[i] <= '9') {
            answer *= 10;
            answer += s[i] - '0';
            i++;
        }
        else {
            for (int j = 0; j < 10; j++) {
                string number = numbers[j];
                string comp = s.substr(i, number.length());
                if (number == comp) {
                    answer *= 10;
                    answer += j;
                    i += number.length();
                }
            }
        }
    }
    
    return answer;
}