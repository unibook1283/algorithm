#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++) {
        vector<int> sub_array;
        int a = commands[i][0] - 1;
        int b = commands[i][1] - 1;
        int c = commands[i][2] - 1;
        for (int j = a; j <= b; j++) {
            sub_array.push_back(array[j]);
        }
        sort(sub_array.begin(), sub_array.end());
        int value = sub_array[c];
        answer.push_back(value);
    }

    return answer;
}