#include <iostream>
#include <string>
#include <vector>

std::vector<int> make_pi(const std::string& pattern) {
    int len = pattern.length();
    std::vector<int> pi(len);
    for (int i = 1; i < len; ++i) {
        int j = pi[i - 1];
        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            ++j;
        }
        pi[i] = j;
    }

    return pi;
}

std::vector<int> kmp_search(const std::string& text, const std::string& pattern) {
    int text_len = text.size();
    int pattern_len = pattern.size();
    std::vector<int> pi = make_pi(pattern);
    std::vector<int> positions;
    int j = 0;
    for (int i = 0; i < text_len; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (text[i] == pattern[j]) {
            ++j;
        }
        if (j == pattern_len) {
            positions.push_back(i - pattern_len + 1);
            j = pi[j - 1];
        }
    }
    return positions;
}

int main() {
    std::string text = "abababab";
    std::string pattern = "aba";

    std::vector<int> positions = kmp_search(text, pattern);

    for (int position : positions) {
        std::cout << position << ' ';
    }
    std::cout << '\n';

    return 0;
}