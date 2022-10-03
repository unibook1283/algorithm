#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> m;
    for (int i = 0; i < skill.size(); i++) {
        m[skill[i]] = i + 1;
    }
    for (int i = 0; i < skill_trees.size(); i++) {
        string skill_tree = skill_trees[i];
        int cur = 1;
        for (int j = 0; j < skill_tree.size(); j++) {
            if (m[skill_tree[j]] > cur) break;
            else if (m[skill_tree[j]] == cur) {
                cur++;
            }
            if (j == skill_tree.size() - 1) answer++;
        }
    }
    return answer;
}