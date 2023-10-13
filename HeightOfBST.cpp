#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* root;

    int findHeight(TreeNode* node) {
        if (node == nullptr) {
            return -1;
        } else {
            int leftHeight = findHeight(node->left);
            int rightHeight = findHeight(node->right);
            return max(leftHeight, rightHeight) + 1;
        }
    }
};

int main() {
    BinaryTree bst;

    // Construct a sample BST
    bst.root = new TreeNode(55);
    bst.root->left = new TreeNode(35);
    bst.root->right = new TreeNode(75);
    bst.root->left->left = new TreeNode(25);
    bst.root->left->right = new TreeNode(45);
    bst.root->right->left = new TreeNode(65);
    bst.root->right->right = new TreeNode(85);

    int height = bst.findHeight(bst.root);
    cout << "Height of the BST is: " << height << endl;

    return 0;
}
