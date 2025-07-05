#include <iostream>
#include <vector>

// Best: O(n) [1, 2, 3, 4, 5]
// Worst: O(n^2) [5, 4, 3, 2, 1]
// Average: O(n^2)
// Stable: true [2, 1, 2]

void bubble_sort(std::vector<int>& vec) {
    int n = vec.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

void print_vec(const std::vector<int>& vec) {
    for (const auto& item : vec) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> case_1 = {7, 6, 5, 4, 3, 2};
    std::vector<int> case_2 = {8, 2, 1, 3, 4};
    std::vector<int> case_3 = {1, 2, 3};

    bubble_sort(case_1);
    bubble_sort(case_2);
    bubble_sort(case_3);

    print_vec(case_1);
    print_vec(case_2);
    print_vec(case_3);

    return 0;
}