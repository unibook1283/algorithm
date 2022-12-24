#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int x;
    int y;
    int n;
    Node* left;
    Node* right;
};
Node nodes[10001];

bool cmp(Node u, Node v) {
    if (u.y == v.y) return u.x < v.x;
    return u.y > v.y;
}
void insert_node(Node* node, int i) {
    if (nodes[i].x < node->x) {
        if (node->left == NULL)
            node->left = &nodes[i];
        else
            insert_node(node->left, i);
    }
    else {
        if (node->right == NULL)
            node->right = &nodes[i];
        else
            insert_node(node->right, i);
    }
}
void preorder_traverse(Node* node, vector<vector<int>>& answer) {
    if (node == NULL) return;
    answer[0].push_back(node->n);
    preorder_traverse(node->left, answer);
    preorder_traverse(node->right, answer);
}
void postorder_traverse(Node* node, vector<vector<int>>& answer) {
    if (node == NULL) return;
    postorder_traverse(node->left, answer);
    postorder_traverse(node->right, answer);
    answer[1].push_back(node->n);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    int N = nodeinfo.size();
    for (int i = 0; i < N; i++) {
        nodes[i].x = nodeinfo[i][0];
        nodes[i].y = nodeinfo[i][1];
        nodes[i].n = i + 1;
    }
    sort(nodes, nodes + N, cmp);

    Node* root = &nodes[0];
    for (int i = 1; i < N; i++) {
        insert_node(root, i);
    }

    preorder_traverse(root, answer);
    postorder_traverse(root, answer);

    return answer;
}