#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    ~TreeNode() {}
};

TreeNode* crearArbolEjercicio4() {
    TreeNode* root = new TreeNode(8);

    root->left = new TreeNode(3);
    root->right = new TreeNode(10);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);

    root->right->right = new TreeNode(14);

    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);

    root->right->right->left = new TreeNode(13);

    return root;
}

void zigzagConSuma(TreeNode* root) {
    // Implementar aquí.
}

int main() {
    TreeNode* root = crearArbolEjercicio4();

    zigzagConSuma(root);

    return 0;
}