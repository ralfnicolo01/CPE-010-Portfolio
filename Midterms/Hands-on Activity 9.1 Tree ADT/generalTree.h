#ifndef GENERALTREE_H
#define GENERALTREE_H
 
const int MAX_CHILDREN = 10;
 
struct TreeNode {
    char data;
    TreeNode* children[MAX_CHILDREN];
    int childCount;
 
    TreeNode(char value) {
        data = value;
        childCount = 0;
        for (int i = 0; i < MAX_CHILDREN; i++) {
            children[i] = nullptr;
        }
    }
};
 
class GeneralTree {
private:
    TreeNode* root;
 
    TreeNode* findNode(TreeNode* node, char value) {
        if (node == nullptr) return nullptr;
        if (node->data == value) return node;
        for (int i = 0; i < node->childCount; i++) {
            TreeNode* found = findNode(node->children[i], value);
            if (found != nullptr) return found;
        }
        return nullptr;
    }
 
    void preOrderFind(TreeNode* node, char key, bool& found) {
        if (node == nullptr || found) return;
        if (node->data == key) {
            found = true;
            return;
        }
        for (int i = 0; i < node->childCount; i++) {
            preOrderFind(node->children[i], key, found);
        }
    }
 
    void inOrderFind(TreeNode* node, char key, bool& found) {
        if (node == nullptr || found) return;
        if (node->childCount == 0) {
            if (node->data == key) found = true;
            return;
        }
        inOrderFind(node->children[0], key, found);
        if (found) return;
        if (node->data == key) {
            found = true;
            return;
        }
        for (int i = 1; i < node->childCount; i++) {
            inOrderFind(node->children[i], key, found);
            if (found) return;
        }
    }
 
    void postOrderFind(TreeNode* node, char key, bool& found) {
        if (node == nullptr || found) return;
        for (int i = 0; i < node->childCount; i++) {
            postOrderFind(node->children[i], key, found);
            if (found) return;
        }
        if (node->data == key) found = true;
    }
 
public:
    GeneralTree(char rootValue) {
        root = new TreeNode(rootValue);
    }
 
    TreeNode* getRoot() { return root; }
 
    void addChild(char parentValue, char childValue) {
        TreeNode* parent = findNode(root, parentValue);
        if (parent != nullptr) {
            if (parent->childCount < MAX_CHILDREN) {
                parent->children[parent->childCount] = new TreeNode(childValue);
                parent->childCount++;
            } else {
                std::cout << "Max children reached for " << parentValue << std::endl;
            }
        } else {
            std::cout << "Parent " << parentValue << " not found." << std::endl;
        }
    }
 
    void preOrder(TreeNode* node) {
        if (node == nullptr) return;
        std::cout << node->data << " ";
        for (int i = 0; i < node->childCount; i++) {
            preOrder(node->children[i]);
        }
    }
 
    void postOrder(TreeNode* node) {
        if (node == nullptr) return;
        for (int i = 0; i < node->childCount; i++) {
            postOrder(node->children[i]);
        }
        std::cout << node->data << " ";
    }
 
    void inOrder(TreeNode* node) {
        if (node == nullptr) return;
        if (node->childCount == 0) {
            std::cout << node->data << " ";
            return;
        }
        inOrder(node->children[0]);
        std::cout << node->data << " ";
        for (int i = 1; i < node->childCount; i++) {
            inOrder(node->children[i]);
        }
    }
 
    void findData(int choice, char key) {
        bool found = false;
        if (choice == 1) {
            preOrderFind(root, key, found);
        } else if (choice == 2) {
            inOrderFind(root, key, found);
        } else if (choice == 3) {
            postOrderFind(root, key, found);
        }
        if (found) {
            std::cout << key << " was found!" << std::endl;
        }
    }
};
 
#endif
