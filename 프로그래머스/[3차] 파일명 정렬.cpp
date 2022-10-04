#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct hnti {
    string head;
    string number;
    string tail;
    int index;
};
string to_lower(string s) {
    string ret;
    for (int i = 0; i < s.length(); i++) {
        ret += tolower(s[i]);
    }
    return ret;
}
bool cmp(hnti u, hnti v) {
    string uhead = to_lower(u.head);
    string vhead = to_lower(v.head);
    int unum = stoi(u.number);
    int vnum = stoi(v.number);
    if (uhead == vhead) {
        if (unum == vnum) {
            return u.index < v.index;
        }
        return unum < vnum;
    }
    return uhead < vhead;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<hnti> v;
    for (int i = 0; i < files.size(); i++) {
        string file = files[i];
        string head, number, tail;
        int number_start = 0, tail_start = 0;
        for (int j = 0; j < file.length(); j++) {
            if (head == "") {
                if ('0' <= file[j] && file[j] <= '9') {
                    head = file.substr(0, j);
                    number_start = j;
                }
            }
            else if (number == "") {
                if (file[j] < '0' || file[j] > '9') {
                    number = file.substr(number_start, j - number_start);
                    tail_start = j;
                }
                else if (j == file.length() - 1) {

                }
            }
            else {
                tail = file.substr(tail_start);
                break;
            }
        }
        if (number == "") number = file.substr(number_start);
        hnti h = { head, number, tail, i };
        v.push_back(h);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        hnti h = v[i];
        answer.push_back(h.head + h.number + h.tail);
    }

    return answer;
}
int main() {
    vector<string> a = solution({ "F-15" });
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << '\n';
    }
    return 0;
}
/*
문자열 파싱하는게 별로다.
다른 사람 풀이중에 이거 좋은듯.
    for (string file : files) {
        Node node;
        pivot = 0;

        while (!(file[pivot] >= '0' && file[pivot] <= '9'))
            node.head += file[pivot++];
        while (file[pivot] >= '0' && file[pivot] <= '9')
            node.num += file[pivot++];

        node.idx = idx++;
        vec_node.push_back(node);
    }
*/