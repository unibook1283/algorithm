#include <string>
#include <vector>
#include <list>
using namespace std;

void push(int x, list<int>& l) {
    if (l.size() == 0) {
        l.push_back(x);
        return;
    }
    auto iter = l.begin();
    while (x > * iter && iter != l.end()) {
        iter++;
    }
    l.insert(iter, x);
}
void delete_max(list<int>& l) {
    if (!l.empty()) l.pop_back();
}
void delete_min(list<int>& l) {
    if (!l.empty()) l.pop_front();
}
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    list<int> l;
    for (int i = 0; i < operations.size(); i++) {
        string operation = operations[i];
        if (operation == "D 1") {
            delete_max(l);
        }
        else if (operation == "D -1") {
            delete_min(l);
        }
        else {
            int num = stoi(operation.substr(2));
            push(num, l);
        }
    }
    answer.push_back(l.back());
    answer.push_back(l.front());

    return answer;
}