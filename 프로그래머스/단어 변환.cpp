#include <string>
#include <vector>

using namespace std;
bool check[51];
int answer = 0;
bool is_possible(string a, string b) {
    int dif = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            dif++;
        }
    }
    return dif == 1;
}
void go(int cnt, string cur, string target, vector<string> words) {
    if (cur == target) {
        answer = cnt;
        return;
    }
    for (int i = 0; i < words.size(); i++) {
        if (!check[i]) {
            if (is_possible(cur, words[i])) {
                check[i] = true;
                go(cnt + 1, words[i], target, words);
                check[i] = false;
            }
        }
    }
}
int solution(string begin, string target, vector<string> words) {

    go(0, begin, target, words);

    return answer;
}