#include <iostream>
#include <string>
#include <vector>

struct TrieNode {
    TrieNode* children[26] = {nullptr};
    int count = 0;
};

class Trie {
  public:
    Trie() : root_(new TrieNode) {}

    ~Trie() {
        free_node(root_);
    }

    void insert(const std::string& word) {
        TrieNode* node = root_;

        for (char ch : word) {
            int index = ch - 'a';

            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode;
            }

            node = node->children[index];
            node->count++;
        }
    }

    std::string get_unique_prefix(const std::string& word) {
        TrieNode* node = root_;
        std::string prefix;

        for (char ch : word) {
            int index = ch - 'a';

            node = node->children[index];
            prefix += ch;

            if (node->count == 1) {
                break;
            }
        }

        return prefix;
    }

  private:
    void free_node(TrieNode* node) {
        for (TrieNode* child : node->children) {
            if (child != nullptr) {
                free_node(child);
            }
        }

        delete node;
    }

    TrieNode* root_;
};

int main() {
    std::vector<std::string> words = {"dog", "cat", "apple", "apricot", "fish"};

    Trie trie;
    for (const std::string& word : words) {
        trie.insert(word);
    }

    for (const std::string& word : words) {
        std::cout << trie.get_unique_prefix(word) << std::endl;
    }

    return 0;
}