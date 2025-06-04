#include <iostream>
#include <vector>
#include <string>

std::vector<int> build_pi(const std::string& pattern) {
    int m = pattern.size();
    std::vector<int> pi(m, 0);

    for (int i = 1; i < m; ++i) {
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
    int n = text.size();
    int m = pattern.size();
    std::vector<int> pi = build_pi(pattern);
    std::vector<int> positions;

    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }

        if (text[i] == pattern[j]) {
            ++j;
        }

        if (j == m) {
            positions.push_back(i - m + 1);
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
    std::cout << std::endl;

    return 0;
}