#include <array>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct TrieNode {
    std::array<std::unique_ptr<TrieNode>, 26> children{};
    int count = 0;
};

class Trie {
  public:
    Trie() : root_(std::make_unique<TrieNode>()) {}

    void insert(const std::string& word) const {
        TrieNode* node = root_.get();

        for (char letter : word) {
            int index = letter - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = std::make_unique<TrieNode>();
            }
            node = node->children[index].get();
            ++node->count;
        }
    }

    std::string get_unique_prefix(const std::string& word) const {
        const TrieNode* node = root_.get();
        std::string prefix;

        for (char letter : word) {
            int index = letter - 'a';
            node = node->children[index].get();
            prefix += letter;
            if (node->count == 1) {
                break;
            }
        }
        return prefix;
    }

    std::unique_ptr<TrieNode> root_;
};

int main() {
    std::vector<std::string> words{"dog", "cat", "apple", "apricot", "fish"};

    Trie trie;
    for (const std::string& word : words) {
        trie.insert(word);
    }

    for (const std::string& word : words) {
        std::cout << trie.get_unique_prefix(word) << '\n';
    }

    return 0;
}