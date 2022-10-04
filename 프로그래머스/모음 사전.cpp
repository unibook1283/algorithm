#include <string>
#include <vector>
#include <algorithm>

using namespace std;
char alpha[5] = { 'A', 'E', 'I', 'O', 'U' };
int cnt = 1;
vector<string> v;
void go(int index, string s) {
    if (index == 5) {
        v.push_back(s);
        return;
    }
    go(index + 1, s);
    for (int i = 0; i < 5; i++) {
        go(index + 1, s + alpha[i]);
    }
}
int solution(string word) {
    int answer = 0;
    go(0, "");
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == word) {
            answer = i;
            break;
        }
    }
    return answer;
}