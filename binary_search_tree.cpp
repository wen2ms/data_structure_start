#include <iostream>
#include <memory>

struct TreeNode {
    explicit TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}

    int val;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;
};

class BST {
  public:
    BST() : root_(nullptr) {}

    void insert(int val) {
        insert(root_, val);
    }

    void inorder() const {
        inorder(root_);
        std::cout << '\n';
    }

    bool find(int val) const {
        return find(root_, val);
    }

    bool remove(int val) {
        return remove(root_, val);
    }

  private:
    void insert(std::unique_ptr<TreeNode>& node, const int val) {
        if (node == nullptr) {
            node = std::make_unique<TreeNode>(val);
            return;
        }
        if (val < node->val) {
            insert(node->left, val);
        } else if (val > node->val) {
            insert(node->right, val);
        }
    }

    void inorder(const std::unique_ptr<TreeNode>& node) const {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        std::cout << node->val << ' ';
        inorder(node->right);
    }

    bool find(const std::unique_ptr<TreeNode>& node, const int val) const {
        if (node == nullptr) {
            return false;
        }
        if (node->val == val) {
            return true;
        }
        return node->val < val ? find(node->left, val) : find(node->right, val);
    }

    bool remove(std::unique_ptr<TreeNode>& node, const int val) {
        if (node == nullptr) {
            return false;
        }
        if (node->val < val) {
            return remove(node->right, val);
        } else if (node->val > val) {
            return remove(node->left, val);
        } else {
            if (node->left == nullptr) {
                node = std::move(node->right);
            } else if (node->right == nullptr) {
                node = std::move(node->left);
            } else {
                TreeNode* right_min_node = node->right.get();
                while (right_min_node != nullptr && right_min_node->left != nullptr) {
                    right_min_node = right_min_node->left.get();
                }
                node->val = right_min_node->val;
                remove(node->right, right_min_node->val);
            }
            return true;
        }
    }

    std::unique_ptr<TreeNode> root_;
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
    std::cout << bst.find(key) << '\n';

    bst.remove(30);
    bst.inorder();

    return 0;
}