#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    for (int i = 0; i < clothes.size(); i++) {
        string type = clothes[i][1];
        m[type]++;
    }
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        answer *= iter->second + 1;
    }
    answer--;
    return answer;
}