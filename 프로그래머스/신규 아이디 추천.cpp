#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";

    // 1단계
    for (char& ch : new_id) {
        if ('A' <= ch && ch <= 'Z') {
            ch -= 'A' - 'a';
        }
    }

    // 2단계
    for (int i = 0; i < new_id.length();) {
        char ch = new_id[i];
        if (('a' <= ch && ch <= 'z') || ('0' <= ch && ch <= '9')
            || ch == '-' || ch == '_' || ch == '.') {
            i++;
            continue;
        }
        new_id.erase(new_id.begin() + i);
    }

    // 3단계
    for (int i = 0; i < new_id.length() - 1;) {
        if (new_id[i] == '.' && new_id[i + 1] == '.') {
            new_id.erase(new_id.begin() + i + 1);
        }
        else i++;
    }

    // 4단계
    if (new_id[0] == '.') new_id.erase(new_id.begin());
    if (new_id[new_id.length() - 1] == '.') new_id.erase(new_id.begin() + new_id.length() - 1);

    // 5단계
    if (new_id == "") new_id = 'a';

    // 6단계
    if (new_id.length() >= 16) {
        for (int i = 15; i < new_id.length();)
            new_id.erase(new_id.begin() + i);
    }
    if (new_id[new_id.length() - 1] == '.')
        new_id.erase(new_id.begin() + new_id.length() - 1);

    // 7단계
    if (new_id.length() <= 2) {
        char ch = new_id[new_id.length() - 1];
        while (new_id.length() < 3) {
            new_id += ch;
        }
    }

    answer = new_id;

    return answer;
}