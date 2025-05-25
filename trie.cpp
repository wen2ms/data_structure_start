#include <iostream>
#include <unordered_map>
#include <vector>

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
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
            if (!node->children[ch]) {
                node->children[ch] = new TrieNode;
            }

            node = node->children[ch];
            node->count++;
        }
    }

    std::string get_unique_prefix(const std::string& word) {
        TrieNode* node = root_;
        std::string prefix;

        for (char ch : word) {
            node = node->children[ch];
            prefix += ch;

            if (node->count == 1) {
                break;
            }
        }

        return prefix;
    }

  private:
    void free_node(TrieNode* node) {
        for (auto& pair : node->children) {
            free_node(pair.second);
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