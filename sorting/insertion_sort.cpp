#include <iostream>
#include <vector>

// Best: O(n) [1, 2, 3, 4, 5]
// Worst: O(n^2) [5, 4, 3, 2, 1]
// Average: O(n^2)
// Stable: true [1, 2, 3, 2, 4]

void insertion_sort(std::vector<int>& vec) {
    int n = vec.size();

    for (int i = 1; i < n; ++i) {
        int key = vec[i];
        int j = i - 1;

        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
        }

        vec[j + 1] = key;
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

    insertion_sort(case_1);
    insertion_sort(case_2);
    insertion_sort(case_3);

    print_vec(case_1);
    print_vec(case_2);
    print_vec(case_3);

    return 0;
}