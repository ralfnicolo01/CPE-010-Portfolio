#include <iostream>

// tree node with a left and a right child
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int value) {
    TreeNode* node = new TreeNode;
    node->val = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// preorder traversal (DFS for trees)
void preorder(TreeNode* node) {
    if (node == nullptr) return;     // nothing here, go back
    std::cout << node->val << " ";   // visit the node first
    preorder(node->left);            // go deep into the left child
    preorder(node->right);           // then the right child
}

int main() {
    // small example tree:
    // 1 has children 2 (left) and 3 (right)
    // 2 has children 4 (left) and 5 (right)
    TreeNode* n1 = createNode(1);
    TreeNode* n2 = createNode(2);
    TreeNode* n3 = createNode(3);
    TreeNode* n4 = createNode(4);
    TreeNode* n5 = createNode(5);
    n1->left = n2;  n1->right = n3;
    n2->left = n4;  n2->right = n5;

    std::cout << "Preorder: ";
    preorder(n1);
    std::cout << std::endl;
    return 0;
}