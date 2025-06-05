#include <iostream>

struct TreeNode {
    TreeNode() : value(-1), left(nullptr), right(nullptr) {}
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : value(val), left(left), right(right) {}

    int value;
    TreeNode* left;
    TreeNode* right;
};

class BST {
  public:
    BST() : root_(nullptr) {}

    void insert(int val) {
        root_ = insert(root_, val);
    }

    void inorder() {
        inorder(root_);

        std::cout << std::endl;
    }

    bool search(int val) {
        return search(root_, val);
    }

    void remove(int val) {
        root_ = remove(root_, val);
    }

  private:
    TreeNode* insert(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }

        if (val < node->value) {
            node->left = insert(node->left, val);
        } else if (val > node->value) {
            node->right = insert(node->right, val);
        }

        return node;
    }

    void inorder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        inorder(node->left);

        std::cout << node->value << ' ';

        inorder(node->right);
    }

    bool search(TreeNode* node, int val) {
        if (node == nullptr) {
            return false;
        }

        if (node->value == val) {
            return true;
        }

        return val < node->value ? search(node->left, val) : search(node->right, val);
    }

    TreeNode* find_min(TreeNode* node) {
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }

        return node;
    }

    TreeNode* remove(TreeNode* node, int val) {
        if (node == nullptr) {
            return nullptr;
        }

        if (val < node->value) {
            node->left = remove(node->left, val);
        } else if (val > node->value) {
            node->right = remove(node->right, val);
        } else {
            if (node->left == nullptr) {
                TreeNode* tmp = node->right;
                delete node;
                return tmp;
            } else if (node->right == nullptr) {
                TreeNode* tmp = node->left;
                delete node;
                return tmp;
            } else {
                TreeNode* min_right = find_min(node->right);
                node->value = min_right->value;
                node->right = remove(node->right, min_right->value);
            }
        }

        return node;
    }

    TreeNode* root_;
};

int main() {
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    bst.inorder();

    int key = 40;
    std::cout << bst.search(key) << std::endl;

    bst.remove(30);
    bst.inorder();

    return 0;
}