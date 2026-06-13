#include <iostream>
#include <stack>
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

TreeNode* crearArbolEjercicio3() {
    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(18);

    root->left->right->left = new TreeNode(6);
    root->right->left->right = new TreeNode(14);

    return root;
}

int sumaRangoABB(TreeNode* root, int low, int high) {
    // Implementar aquí.
    return 0;
}

int main() {
    TreeNode* root = crearArbolEjercicio3();

    int low = 6;
    int high = 15;

    int resultado = sumaRangoABB(root, low, high);

    cout << resultado << endl;

    return 0;
}