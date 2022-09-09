#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> m;
    m['R'] = 0;
    m['T'] = 0;
    m['C'] = 0;
    m['F'] = 0;
    m['J'] = 0;
    m['M'] = 0;
    m['A'] = 0;
    m['N'] = 0;

    for (int i = 0; i < survey.size(); i++) {
        string s = survey[i];
        int choice = choices[i];
        if (choice < 4) m[s[0]] += 4 - choice;
        else if (choice == 4) continue;
        else m[s[1]] += choice - 4;
    }

    if (m['R'] >= m['T']) answer += 'R';
    else answer += 'T';
    if (m['C'] >= m['F']) answer += 'C';
    else answer += 'F';
    if (m['J'] >= m['M']) answer += 'J';
    else answer += 'M';
    if (m['A'] >= m['N']) answer += 'A';
    else answer += 'N';

    return answer;
}