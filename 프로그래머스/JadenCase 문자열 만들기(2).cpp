#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = s;
    answer.front() = toupper(answer.front());
    for (int i = 1; i < answer.length(); i++) {
        if (answer[i - 1] == ' ') {
            answer[i] = toupper(answer[i]);
        }
        else {
            answer[i] = tolower(answer[i]);
        }
    }
    
    return answer;
}