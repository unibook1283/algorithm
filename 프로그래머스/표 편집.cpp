#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    bool removed;
    Node* prev;
    Node* next;
};
Node nodes[1000001];

string solution(int n, int k, vector<string> cmd) {
    string answer = "";

    for (int i = 0; i < n - 1; i++) {
        nodes[i].next = &nodes[i + 1];
        nodes[i + 1].prev = &nodes[i];
    }

    Node* cur = &nodes[k];
    stack<Node*> s;
    for (int i = 0; i < cmd.size(); i++) {
        string str = cmd[i];
        if (str == "C") {
            cur->removed = true;
            s.push(cur);
            Node* up = cur->prev;
            Node* down = cur->next;
            if (up)
                up->next = down;
            if (down) {
                down->prev = up;
                cur = down;
            }
            else {
                cur = up;
            }
        }
        else if (str == "Z") {
            Node* node = s.top();
            s.pop();
            node->removed = false;
            Node* up = node->prev;
            Node* down = node->next;
            if (up)
                up->next = node;
            if (down)
                down->prev = node;
        }
        else if (str[0] == 'U') {
            int d = stoi(str.substr(2));
            for (int i = 0; i < d; i++)
                cur = cur->prev;
        }
        else if (str[0] == 'D') {
            int d = stoi(str.substr(2));
            for (int i = 0; i < d; i++)
                cur = cur->next;
        }
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i].removed) answer.push_back('X');
        else answer.push_back('O');
    }

    return answer;
}