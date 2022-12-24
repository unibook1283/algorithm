#include <iostream>
using namespace std;
struct Node {
	char ch;
	Node* left;
	Node* right;
};
Node nodes[26];
void preorder(Node* node) {
	if (node == NULL) return;
	cout << node->ch;
	preorder(node->left);
	preorder(node->right);
}
void inorder(Node* node) {
	if (node == NULL) return;
	inorder(node->left);
	cout << node->ch;
	inorder(node->right);
}
void postorder(Node* node) {
	if (node == NULL) return;
	postorder(node->left);
	postorder(node->right);
	cout << node->ch;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char ch, left, right;
		cin >> ch >> left >> right;
		int index = ch - 'A';
		nodes[index].ch = ch;
		if (left != '.')
			nodes[index].left = &nodes[left - 'A'];
		if (right != '.')
			nodes[index].right = &nodes[right - 'A'];
	}
	preorder(&nodes[0]);
	cout << '\n';
	inorder(&nodes[0]);
	cout << '\n';
	postorder(&nodes[0]);
	cout << '\n';

	return 0;
}