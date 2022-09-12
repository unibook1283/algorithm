#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, bool> m;

    char start = words[0].front();
    int i;
    for (i = 0; i < words.size(); i++) {
        string word = words[i];
        if (word.front() != start) {
            break;
        }
        start = word.back();
        if (m[word]) {
            break;
        }
        m[word] = true;
    }
    answer.push_back(i % 3 + 1);
    answer.push_back(i / 3 + 1);

    return answer;
}